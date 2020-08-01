#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;

int main()
{
    // читаем число
    UShort N;
    cin >> N;

    // переводим в двоичный вид
    vector<UShort> answer;
    while( N > 1 )
    {
        answer.push_back( N % 2 );
        N /= 2;
    }
    answer.push_back( N );

    // не забыть развернуть ответ
    reverse( answer.begin(), answer.end() );

    for( auto elem : answer )
        cout << elem;

    return 0;
}
