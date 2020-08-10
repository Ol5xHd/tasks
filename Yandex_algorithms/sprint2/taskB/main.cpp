#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned short UShort;

int main()
{
    string line;

    getline( cin, line );
    UShort N = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    stringstream sstream( line );
    vector<UShort> prices( N );
    for( UShort i = 0; i < N; ++i )
    {
        UShort price;
        sstream >> price;
        prices[ i ] = price;
    }

    unsigned long total_profit = 0;
    bool opened = false;
    for( UShort i = 1; i < prices.size(); ++i )
    {
        if( opened )
        {
            if( prices[ i ] < prices[ i - 1 ] )
            {
                total_profit += prices[ i - 1 ];
                opened = false;
            }
        }
        else
        {
            if( prices[ i ] > prices[ i - 1 ] )
            {
                total_profit -= prices[ i - 1 ];
                opened = true;
            }
        }
    }
    if( opened )
        total_profit += *( prices.rbegin() );

    cout << total_profit << endl;

    return 0;
}
