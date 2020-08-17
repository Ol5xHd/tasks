#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned long long ULL;
typedef unsigned short UShort;

ULL Fact( UShort N )
{
    ULL result = 1;

    for( UShort i = 2; i <= N; ++i )
        result *= i;

    return result;
}

int main()
{
    ifstream fin;
    fin.open( "input.txt" );
    UShort N = 0;
    fin >> N;

    cout << Fact( N );

    return 0;
}
