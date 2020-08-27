#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned short UShort;

void Swap( vector<UShort> &elems, UShort first, UShort second )
{
    UShort tmp = elems[ first ];
    elems[ first ] = elems[ second ];
    elems[ second ] = tmp;
}

int main()
{
    string line;

    getline( cin, line );
    UShort length = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    stringstream input_sstream( line );
    vector<UShort> elems( length );
    for( UShort i = 0; i < length; ++i )
        input_sstream >> elems[ i ];

    for( UShort i = 0; i < length; ++i )
    {
        if( i % 2 == 0 && elems[ i ] % 2 != 0 ) // на чётной позиции нечётный элемент
        {
            for( UShort j = i + 1; j < length; ++j )
            {
                if( elems[ j ] % 2 == 0 )
                {
                    Swap( elems, i, j );
                    break;
                }
                else if( elems[ j ] % 2 != 0 )
                {
                    Swap( elems, i, j );
                }
            }
        }
        else if( i % 2 != 0 && elems[ i ] % 2 == 0 )
        {
            for( UShort j = i + 1; j < length; ++j )
            {
                if( elems[ j ] % 2 != 0 )
                {
                    Swap( elems, i, j );
                    break;
                }
                else if( elems[ j ] % 2 == 0 )
                {
                    Swap( elems, i, j );
                }
            }
        }
    }

    for( const UShort el : elems )
        cout << el << ' ';

    return 0;
}
