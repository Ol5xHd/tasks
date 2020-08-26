#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned short UShort;

void QuicksortRecursive( vector<short> &elems, UShort beg, UShort end )
{
    if( end == beg )
    {
        return;
    }
    else
    {
        short base = elems[ beg ];
        UShort cnt_less_eq = 0;
        UShort cnt_greater = 0;
        for( UShort i = beg + 1; i <= end; ++i )
        {
            if( elems[ i ] <= base )
                ++cnt_less_eq;
            else if( elems[ i ] > base )
                ++cnt_greater;
        }

        UShort base_ind = beg + cnt_less_eq;
        if( cnt_less_eq != 0 )
        {
            short tmp = elems[ beg ];
            elems[ beg ] = elems[ base_ind ];
            elems[ base_ind ] = tmp;
        }

        UShort left_ind = beg;
        UShort right_ind = base_ind + 1;
        while( left_ind < base_ind )
        {
            if( elems[ left_ind ] > base )
            {
                while( elems[ right_ind ] > base )
                    ++right_ind;
                short tmp = elems[ left_ind ];
                elems[ left_ind ] = elems[ right_ind ];
                elems[ right_ind ] = tmp;
            }
            else
            {
                ++left_ind;
            }
        }

        if( beg <= base_ind - 1 )
            QuicksortRecursive( elems, beg, base_ind - 1 );
        if( base_ind + 1 <= end )
            QuicksortRecursive( elems, base_ind + 1, end );
    }

}

void Quicksort( vector<short> &elems )
{
    QuicksortRecursive( elems, 0, elems.size() - 1 );
}

int main()
{
    string line;

    getline( cin, line );
    UShort length = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    stringstream input_sstream( line );
    vector<short> elems( length );
    for( UShort i = 0; i < length; ++i )
        input_sstream >> elems[ i ];

    Quicksort( elems );

    for( const short elem : elems )
        cout << elem << ' ';

    return 0;
}
