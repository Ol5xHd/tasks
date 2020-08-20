#include <iostream>

using namespace std;

double abs( double left, double right )
{
    if( left > right )
        return left - right;
    else
        return right - left;
}

int main()
{
    unsigned short a = 2;
    double prev = 0;
    double curr = 2;
    while( abs( curr, prev ) > 0.00001 )
    {
        prev = curr;
        curr = 0.5 * ( prev + a / prev );
    }

    cout << curr;

    return 0;
}
