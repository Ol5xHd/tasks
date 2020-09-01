#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;

void RelativeSort( vector<UShort> &sorting, vector<UShort> &pattern )
{
    vector<UShort> result;

    map<UShort, UShort> counts;
    for( UShort it : pattern )
        counts[ it ] = 0;

    vector<UShort> not_sorted;
    for( UShort i = 0; i < sorting.size(); ++i )
    {
        if( counts.find( sorting[ i ] ) != counts.end() )
            counts[ sorting[ i ] ] += 1;
        else
            not_sorted.push_back( sorting[ i ] );
    }

    for( UShort it : pattern )
    {
        if( counts.find( it ) != counts.end() )
        {
            for( UShort j = 0; j < counts[ it ]; ++j )
                result.push_back( it );
        }
    }
    sort( not_sorted.begin(), not_sorted.end() );
    for( UShort it : not_sorted )
        result.push_back( it );

    sorting.swap( result );
}

int main()
{
    string line;

    getline( cin, line );
    UShort N = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    stringstream in_sstream( line );
    vector<UShort> sorting( N );
    for( UShort i = 0; i < N; ++i )
        in_sstream >> sorting[ i ];

    getline( cin, line );
    UShort M = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    in_sstream.clear();
    in_sstream.str( line );
    vector<UShort> pattern( M );
    for( UShort i = 0; i < M; ++i )
        in_sstream >> pattern[ i ];

    RelativeSort( sorting, pattern );

    for( UShort it : sorting )
        cout << it << ' ';

    return 0;
}
