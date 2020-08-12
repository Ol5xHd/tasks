#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned short UShort;

int main()
{
    UShort str_count = 0;
    cin >> str_count;

    UShort str_length = 0;
    cin >> str_length;

    vector<string> strings( str_count );
    for( UShort i = 0 ; i < str_count; ++i )
        cin >> strings[ i ];

    UShort idx_to_delete = 0;
    for( UShort i = 0; i < str_length; ++i )
    {
        for( UShort j = 1; j < str_count; ++j )
        {
            if( strings[ j ][ i ] < strings[ j - 1 ][ i ] )
            {
                ++idx_to_delete;
                break;
            }
        }
    }

    cout << idx_to_delete;

    return 0;
}
