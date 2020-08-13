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
    vector<short> points( N );
    for( UShort i = 0; i < N; ++i )
        sstream >> points[ i ];

    UShort max_increasing_count = 1;
    UShort curr_increasing_count = 1;
    for( UShort i = 1; i < N; ++i )
    {
        if( points[ i ] > points[ i - 1 ] )
        {
            ++curr_increasing_count;
        }
        else
        {
            if( curr_increasing_count > max_increasing_count )
                max_increasing_count = curr_increasing_count;
            curr_increasing_count = 1;
        }
    }

    cout << max_increasing_count;

    return 0;
}
