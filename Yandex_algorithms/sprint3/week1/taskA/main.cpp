#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void Bubble( vector<short> &elems )
{
    if( elems.size() == 1 )
        return;

    bool sorted = false;
    while( !sorted )
    {
        sorted = true;
        for( unsigned short i = 1; i < elems.size(); ++i )
        {
            if( elems[ i - 1 ] > elems[ i ] )
            {
                short tmp = elems[ i - 1 ];
                elems[ i - 1 ] = elems[ i ];
                elems[ i ] = tmp;
                sorted = false;
            }
        }
    }
}

int main()
{
    string line;

    getline( cin, line );
    unsigned short length = static_cast<unsigned short>( stoi( line ) );

    getline( cin, line );
    stringstream input_sstream( line );
    vector<short> elems( length );
    for( unsigned short i = 0; i < length; ++i )
        input_sstream >> elems[ i ];

    Bubble( elems );

    for( const short elem : elems )
        cout << elem << ' ';

    return 0;
}
