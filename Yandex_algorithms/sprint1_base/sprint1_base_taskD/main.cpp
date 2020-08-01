#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

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
        for( short curr_num, ind = 0; sstream >> curr_num; ++ind )
            matrix[ i ][ ind ] = curr_num;
    }

    getline( cin, line );
    UShort target_row = static_cast<UShort>( stoi( line ) );
    getline( cin, line );
    UShort target_col = static_cast<UShort>( stoi( line ) );

    vector<short> answer;
    if( target_col < cols - 1 ) // элемент справа
        answer.push_back( matrix[ target_row ][ target_col + 1 ] );
    if( target_row > 0 ) // элемент сверху
        answer.push_back( matrix[ target_row - 1 ][ target_col ] );
    if( target_col > 0 ) // элемент слева
        answer.push_back( matrix[ target_row ][ target_col - 1 ] );
    if( target_row < rows - 1 ) // элемент снизу
        answer.push_back( matrix[ target_row + 1 ][ target_col ] );

    sort( answer.begin(), answer.end() );
    for( auto elem : answer )
        cout << elem << ' ';

    return 0;
}
