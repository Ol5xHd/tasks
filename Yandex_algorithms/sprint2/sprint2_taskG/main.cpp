#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef unsigned short UShort;

void Print( short** matrix, short start_row, short start_col, short max_row, short max_col, stringstream &output )
{
    for( short i = start_col; i <= max_col; ++i )
        output << matrix[ start_row ][ i ] << endl;
    for( short i = start_row + 1; i <= max_row; ++i )
        output << matrix[ i ][ max_col ] << endl;
    if( max_row != start_row )
    {
        for( short i = max_col - 1; i >= start_col; --i )
            output << matrix[ max_row ][ i ] << endl;
    }
    if( start_col != max_col )
    {
        for( short i = max_row - 1; i >= start_row + 1; --i )
            output << matrix[ i ][ start_col ] << endl;
    }

    if( max_row > 0 && max_col > 0 && max_row - start_row > 1 && max_col - start_col > 1 )
        Print( matrix, start_row + 1, start_col + 1, max_row - 1, max_col - 1, output );
    else
        return;
}

int main()
{
    string line;

    getline( cin, line );
    UShort rows = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    UShort cols = static_cast<UShort>( stoi( line ) );

    short** matrix = new short*[ rows ];
    for( UShort i = 0; i < rows; ++i )
        matrix[ i ] = new short[ cols ];

    for( UShort i = 0; i < rows; ++i )
    {
        getline( cin, line );
        stringstream sstream( line );
        for( UShort j = 0; j < cols; ++j )
            sstream >> matrix[ i ][ j ];
    }

    stringstream output;
    Print( matrix, 0, 0, rows - 1, cols - 1, output );
    cout << output.str();

    return 0;
}
