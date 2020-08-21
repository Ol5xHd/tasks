#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned short UShort;

UShort GCD( UShort a, UShort b, short &x, short &y )
{
    if( b == 0 )
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        short prev_x = 0;
        short prev_y = 0;
        UShort gcd = GCD( b, a % b, prev_x, prev_y );
        x = prev_y;
        y = prev_x - ( a / b ) * prev_y;
        return gcd;
    }
}

int main()
{
    ifstream fin;
    fin.open( "input.txt" );

    UShort a = 0;
    fin >> a;

    UShort b = 0;
    fin >> b;

    short x = 0;
    short y = 0;
    UShort gcd = GCD( a, b, x, y );

    cout << x << ' ' << y << ' ' << gcd;

    return 0;
}
