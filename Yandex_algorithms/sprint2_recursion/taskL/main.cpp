#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;
typedef unsigned long ULong;

void Combinations( vector<UShort> coins, UShort target_sum, UShort curr_sum, ULong &combinations_cnt )
{
    if( curr_sum == target_sum )
    {
        ++combinations_cnt;
        return;
    }
    else if( curr_sum > target_sum )
    {
        return;
    }
    else // curr_sum < target_sum
    {
        if( coins.empty() )
        {
            return;
        }
        else
        {
            for( auto it = coins.rbegin(); it != coins.rend(); ++it )
            {
                if( *it > target_sum - curr_sum )
                {
                    continue;
                }
                else
                {
                    curr_sum += *it;
                    vector<UShort> new_coins( coins.begin(), it.base() );
                    Combinations( new_coins, target_sum, curr_sum, combinations_cnt );
                    curr_sum -= *it;
                }
            }
        }
    }
}

int main()
{
    ifstream fin;
    fin.open( "input.txt" );
    string line;

    getline( fin, line );
    UShort target_sum = static_cast<UShort>( stoi( line ) );

    getline( fin, line );
    UShort coins_cnt = static_cast<UShort>( stoi( line ) );

    getline( fin, line );
    stringstream sstream( line );
    vector<UShort> coins( coins_cnt );
    for( UShort i = 0; i < coins_cnt; ++i )
        sstream >> coins[ i ];
    sort( coins.begin(), coins.end() );

    ULong combinations_cnt = 0;
    UShort curr_sum = 0;
    Combinations( coins, target_sum, curr_sum, combinations_cnt );

    cout << combinations_cnt;

    return 0;
}
