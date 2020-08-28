#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;

bool IsRectangle( UShort a, UShort b, UShort c )
{
    if(
        a < b + c
        && b < a + c
        && c < a + b
    )
        return true;
    else
        return false;
}

int main()
{
    string line;

    getline( cin, line );
    UShort length = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    stringstream in_sstream( line );
    vector<UShort> elems( length );
    for( UShort i = 0; i < length; ++i )
        in_sstream >> elems[ i ];

    sort( elems.begin(), elems.end() );

    unsigned long max_perimeter = 0;
    for( UShort i = 2; i < length; ++i )
    {
        if( IsRectangle( elems[ i - 2 ], elems[ i - 1 ], elems[ i ] ) )
        {
            unsigned long curr_perimeter = elems[ i - 2 ] + elems[ i - 1 ] + elems[ i ];
            if( curr_perimeter > max_perimeter )
                max_perimeter = curr_perimeter;
        }
    }

    cout << max_perimeter;

    return 0;
}
