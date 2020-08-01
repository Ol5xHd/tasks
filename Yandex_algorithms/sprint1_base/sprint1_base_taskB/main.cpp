#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

typedef unsigned short UShort;

int main()
{
    string line;
    getline( cin, line );
    UShort rows = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    UShort cols = static_cast<UShort>( stoi( line ) );

    short** matrix = new short*[ rows ];
    for( UShort i = 0; i < rows; ++i )
    {
        getline( cin, line );
        stringstream sstream( line );
        matrix[ i ] = new short[ cols ];
        for( short elem, ind = 0; sstream >> elem; ++ind )
            matrix[ i ][ ind ] = elem;
    }

    short **transposed = new short*[ cols ];
    for( short i = 0; i < cols; ++i )
        transposed[ i ] = new short[ rows ];

    for( UShort i = 0; i < rows; ++i )
        for( UShort j = 0; j < cols; ++j )
            transposed[j][i] = matrix[i][j];

    for( UShort i = 0; i < cols; ++i )
    {
        for( UShort j = 0; j < rows; ++j )
            cout << transposed[ i ][ j ] << ' ';
        cout << endl;
    }

    return 0;
}
