#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

typedef unsigned short UShort;

UShort CountGroups( vector<UShort> elems )
{
    UShort groups = 0;

    bool group_opened = false;
    UShort local_max = 0;
    set<UShort> to_find;
    for( UShort i = 0; i < elems.size(); ++i )
    {
        if( group_opened )
        {
            if( elems[ i ] > local_max )
            {
                UShort new_local_max = elems[ i ];
                for( UShort j = local_max + 1; j < new_local_max; ++j )
                    to_find.insert( j );
                local_max = new_local_max;
            }
            else
            {
                to_find.erase( elems[ i ] );
            }
        }
        else
        {
            group_opened = true;
            local_max = elems[ i ];
            for( UShort j = i; j < local_max; ++j )
                to_find.insert( j );
        }

        if( to_find.empty() )
        {
            group_opened = false;
            ++groups;
        }
    }

    return groups;
}

int main()
{
    string line;

    getline( cin, line );
    UShort N = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    stringstream in_sstream( line );
    vector<UShort> elems( N );
    for( UShort i = 0; i < N; ++i )
        in_sstream >> elems[ i ];

    cout << CountGroups( elems );

    return 0;
}
