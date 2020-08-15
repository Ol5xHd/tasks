#include <iostream>
#include <fstream>

using namespace std;

int Fibo( int n )
{
    int res = 0;

    int* arr = new int[ n + 1 ];
    for( size_t i = 0; i <= n; ++i )
    {
        if( i == 0 || i == 1 )
            arr[ i ] = 1;
        else
            arr[ i ] = arr[ i - 2 ] + arr[ i - 1 ];
    }
    res = arr[ n ];
    delete[] arr;

    return res;
}

int main()
{
    ifstream fin( "input.txt" );
    int N;
    fin >> N;

    cout << Fibo( N );

    return 0;
}
