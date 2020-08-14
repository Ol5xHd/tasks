#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned short UShort;

struct Step
{
    Step() : mPower( 0 ), mReachable( false ) {}

    UShort mPower;
    bool mReachable;
};

int main()
{
    string line;

    getline( cin, line );
    UShort steps_count = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    stringstream sstream( line );
    vector<Step> steps( steps_count );
    for( UShort i = 0; i < steps_count; ++i )
        sstream >> steps[ i ].mPower;

    steps[ 0 ].mReachable = true;
    for( UShort i = 0; i < steps_count; ++i )
    {
        if( steps[ i ].mReachable )
        {
            for( UShort j = 1; j <= steps[ i ].mPower; ++j )
            {
                if( i + j < steps_count )
                    steps[ i + j ].mReachable = true;
            }
        }
    }

    if( steps.back().mReachable )
        cout << "True";
    else
        cout << "False";

    return 0;
}
