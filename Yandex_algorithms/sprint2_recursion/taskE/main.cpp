#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned long long ULL;

ULL Fact( int N )
{
    if( N == 0 )
        return 1;
    else
        return N * Fact( N - 1 );
}

int main()
{
    ifstream fin;
    fin.open( "input.txt" );
    int N = 0;
    fin >> N;

    cout << Fact( N );

    return 0;
}
