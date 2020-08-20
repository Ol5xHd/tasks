#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned short UShort;
typedef unsigned long long ULLong;

char GetNewCharByPrevChar( char prev, bool is_even )
{
    char result = '0';
    if( prev == '0' )
        is_even ? result = '1' : result = '0';
    else
        is_even ? result = '0' : result = '1';
    return result;
}

char Func( UShort row_num, ULLong char_num )
{
    if( row_num == 0 )
    {
        return '0';
    }
    else
    {
        char prev = Func( row_num - 1, ( char_num + 1 ) / 2 );
        bool is_even = char_num % 2 == 0;
        return GetNewCharByPrevChar( prev, is_even );
    }
}

int main()
{
    ifstream fin;
    fin.open( "input.txt" );
    UShort row_num = 0;
    fin >> row_num;
    ULLong char_num = 0;
    fin >> char_num;

    cout << Func( row_num, char_num );

    return 0;
}
