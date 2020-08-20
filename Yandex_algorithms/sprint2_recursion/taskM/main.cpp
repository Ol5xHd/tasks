#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned short UShort;

UShort GCF( UShort first, UShort second )
{
    UShort modulo = first % second;
    if( modulo == 0 )
        return second;
    else
        return GCF( second, modulo );
}

int main()
{
    ifstream fin;
    fin.open( "input.txt" );
    UShort width = 0;
    fin >> width;
    UShort length = 0;
    fin >> length;

    cout << GCF( width, length );

    return 0;
}
