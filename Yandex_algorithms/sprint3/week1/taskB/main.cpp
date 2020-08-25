#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void Insertion( vector<short> &elems )
{
    for( unsigned short i = 0; i < elems.size(); ++i )
    {
        for( unsigned short j = i - 1; j < i; --j )
        {
            if( elems[ j ] > elems[ j + 1 ] )
            {
                short tmp = elems[ j + 1 ];
                elems[ j + 1 ] = elems[ j ];
                elems[ j ] = tmp;
            }
        }
    }
}

int main()
{
    string line;

    getline( cin, line );
    unsigned short length = static_cast<unsigned short>( stoi( line ) );

    getline( cin, line );
    stringstream input_sstream( line );
    vector<short> elems( length );
    for( unsigned short i = 0; i < length; ++i )
        input_sstream >> elems[ i ];

    Insertion( elems );

    for( const short elem : elems )
        cout << elem << ' ';

    return 0;
}
