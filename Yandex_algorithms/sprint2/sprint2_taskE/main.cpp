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
    UShort children_count = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    stringstream sstream( line );
    vector<UShort> greed_values( children_count );
    for( UShort i = 0; i < children_count; ++i )
        sstream >> greed_values[ i ];

    getline( cin, line );
    UShort cookies_count = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    sstream.clear();
    sstream.str( line );
    vector<UShort> cookie_sizes( cookies_count );
    for( UShort i = 0; i < cookies_count; ++i )
        sstream >> cookie_sizes[ i ];

    sort( greed_values.begin(), greed_values.end(), []( const UShort &left, const UShort &right ) { return right < left; } );
    sort( cookie_sizes.begin(), cookie_sizes.end(), []( const UShort &left, const UShort &right ) { return right < left; } );

    UShort satisfied = 0;
    while( greed_values.size() > 0 && cookie_sizes.size() > 0 )
    {
        if( greed_values.back() <= cookie_sizes.back() )
        {
            greed_values.pop_back();
            cookie_sizes.pop_back();
            ++satisfied;
        }
        else
        {
            cookie_sizes.pop_back();
        }
    }

    cout << satisfied;

    return 0;
}
