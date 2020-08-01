#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;

int main()
{
    // читаем число
    UShort number;
    cin >> number;

    // переводим в двоичный вид
    vector<UShort> binary_form;
    while( number > 1 )
    {
        binary_form.push_back( number % 2 );
        number /= 2;
    }
    binary_form.push_back( number );

    // не забыть развернуть ответ
    reverse( binary_form.begin(), binary_form.end() );

    // считаем еденицы
    UShort count = 0;
    for( UShort digit : binary_form )
        if( digit == 1 )
            ++count;

    cout << count;

    return 0;
}
