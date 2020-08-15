#include <iostream>
#include <fstream>

using namespace std;

int Fibo( int n )
{
    if( n == 0 || n == 1 )
        return 1;

    int arr[ 3 ] = { 1, 1, 2 };
    int curr_n = 2;
    while( curr_n < n )
    {
        arr[ 0 ] = arr[ 1 ];
        arr[ 1 ] = arr[ 2 ];
        arr[ 2 ] = arr[ 0 ] + arr[ 1 ];
        ++curr_n;
    }

    return arr[ 2 ];
}

int main()
{
    ifstream fin( "input.txt" );
    int N;
    fin >> N;

    cout << Fibo( N );

    return 0;
}
