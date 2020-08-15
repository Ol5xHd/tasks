#include <iostream>
#include <fstream>

using namespace std;

int Fibo( int n )
{
    if( n == 0 || n == 1 )
    {
        return 1;
    }
    else
    {
        return Fibo( n - 2 ) + Fibo( n - 1 );
    }
}

int main()
{
    ifstream fin( "input.txt" );
    int N = 0;
    fin >> N;

    cout << Fibo( N );

    return 0;
}
