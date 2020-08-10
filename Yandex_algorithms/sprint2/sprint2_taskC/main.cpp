#include <iostream>
#include <string>

using namespace std;

int main()
{
    string little;
    getline( cin, little );

    string big;
    getline( cin, big );

    bool is_substr = true;
    size_t j = 0;
    for( size_t i = 0; i < little.size(); ++i )
    {
        bool c_found = false;
        while( j < big.size() )
        {
            if( little[ i ] == big[ j ] )
            {
                ++j;
                c_found = true;
                break;
            }
            else
            {
                ++j;
            }
        }

        if( !c_found )
        {
            is_substr = false;
            break;
        }
    }

    if( is_substr )
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
