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

    UShort houses_count = 0;
    UShort budget = 0;
    getline( cin, line);
    stringstream sstream( line );
    sstream >> houses_count >> budget;

    getline( cin, line );
    sstream.clear();
    sstream.str( line );
    vector<UShort> costs( houses_count );
    for( UShort i = 0; i < houses_count; ++i )
        sstream >> costs[ i ];

    sort( costs.begin(), costs.end() );

    UShort purchased = 0;
    for( UShort curr_cost : costs )
    {
        if( curr_cost <= budget )
        {
            budget -= curr_cost;
            ++purchased;
        }
        else
        {
            break;
        }
    }

    cout << purchased;

    return 0;
}
