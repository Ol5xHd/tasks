#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef unsigned short UShort;

set<UShort> FindDoubles( vector<UShort> elems_first, vector<UShort> elems_second )
{
    set<UShort> doubles;
    sort( elems_first.begin(), elems_first.end() );
    sort( elems_second.begin(), elems_second.end() );
    UShort ind_first = 0;
    UShort ind_second = 0;
    while( ind_first < elems_first.size() && ind_second < elems_second.size() )
    {
        if( elems_first[ ind_first ] < elems_second[ ind_second ] )
        {
            ++ind_first;
        }
        else if( elems_first[ ind_first ] == elems_second[ ind_second ] )
        {
            doubles.insert( elems_first[ ind_first ] );
            ++ind_first;
            ++ind_second;
        }
        else if( elems_first[ ind_first ] > elems_second[ ind_second ] )
        {
            ++ind_second;
        }
    }

    return doubles;
}

int main()
{
    string line;

    getline( cin, line );
    UShort length_first = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    UShort length_second = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    stringstream input_sstream( line );
    vector<UShort> elems_first( length_first );
    for( UShort i = 0; i < length_first; ++i )
        input_sstream >> elems_first[ i ];

    getline( cin, line );
    input_sstream.clear();
    input_sstream.str( line );
    vector<UShort> elems_second( length_second );
    for( UShort i = 0; i < length_second; ++i )
        input_sstream >> elems_second[ i ];

    set<UShort> doubles = FindDoubles( elems_first, elems_second );

    for( const UShort elem : elems_first )
    {
        if( doubles.find( elem ) != doubles.end() )
        {
            cout << elem << ' ';
            doubles.erase( elem );
        }
    }

    return 0;
}
