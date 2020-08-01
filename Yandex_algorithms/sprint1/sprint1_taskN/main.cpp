#include <iostream>

using namespace std;

int main()
{
    // читаем входное число
    unsigned short number;
    cin >> number;

    bool is_power_of_4 = true;
    while( number > 1 )
    {
        if( number % 4 == 0 )
        {
            number /= 4;
        }
        else
        {
            is_power_of_4 = false;
            break;
        }
    }

    if( is_power_of_4 )
        cout << "True";
    else
        cout << "False";

    return 0;
}
