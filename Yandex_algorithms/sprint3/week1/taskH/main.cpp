#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;

void MergeBeds( vector<pair<UShort, UShort>> &beds )
{
    for( size_t i = 0; i < beds.size(); ++i )
    {
        for( size_t j = i + 1; j < beds.size(); ++j )
        {
            if( beds[ j ].first >= beds[ i ].first && beds[ j ].second <= beds[ i ].second )
            {
                beds.erase( beds.begin() + j );
                --j;
            }
            else if( beds[ j ].first <= beds[ i ].first && beds[ j ].second >= beds[ i ].second )
            {
                beds[ i ].first = beds[ j ].first;
                beds[ i ].second = beds[ j ].second;
                beds.erase( beds.begin() + j );
                --j;
            }
            else if( beds[ j ].first <= beds[ i ].second && beds[ j ].second >= beds[ i ].second )
            {
                beds[ i ].second = beds[ j ].second;
                beds.erase( beds.begin() + j );
                --j;
            }
            else if( beds[ j ].first <= beds[ i ].first && beds[ j ].second >= beds[ i ].first )
            {
                beds[ i ].first = beds[ j ].first;
                beds.erase( beds.begin() + j );
                --j;
            }
        }
    }
}

int main()
{
    string line;

    getline( cin, line );
    UShort gardeners = static_cast<UShort>( stoi( line ) );

    vector<pair<UShort, UShort>> beds;
    for( UShort i = 0; i < gardeners; ++i )
    {
        getline( cin, line );
        UShort space_ind = static_cast<UShort>( line.find( ' ' ) );
        UShort beg = static_cast<UShort>( stoi( line.substr( 0, space_ind ) ) );
        UShort end = static_cast<UShort>( stoi( line.substr( space_ind + 1 ) ) );
        bool merged = false;
        for( pair<UShort, UShort> &bed : beds )
        {
            if( beg < bed.first && end >= bed.first )
            {
                bed.first = beg;
                merged = true;
            }
            if( end > bed.second && beg <= bed.second )
            {
                bed.second = end;
                merged = true;
            }
        }
        if( !merged )
            beds.push_back( make_pair( beg, end ) );
    }
    MergeBeds( beds );
    sort( beds.begin(), beds.end(), []( const pair<UShort, UShort> &left, const pair<UShort, UShort> &right ){
        return left.first <= right.second;
    } );

    for( const pair<UShort, UShort> &bed : beds )
        cout << bed.first << ' ' << bed.second << endl;

    return 0;
}
