#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // считываем слово 1
    string word1;
    getline( cin, word1 );

    // считываем слово 2
    string word2;
    getline( cin, word2 );

    // перегоняем первое слово в мапу, причём считаем количество вхождений по каждому символу
    map<char, short> m;
    for( char c : word1 )
    {
        if( m.find( c ) == m.end() )
            m[ c ] = 1;
        else
            m[ c ] += 1;
    }

    // бежим по второму слову и смотрим, какой символ будет лишним
    bool is_found = false;
    for( char c : word2 )
    {
        if( m.find( c ) == m.end() )
        {
            cout << c;
            is_found = true;
            break;
        }
        else
        {
            m[ c ] -= 1;
        }
    }

    // если не нашли явно лишний символ, значит это какой-то повторяющийся
    if( !is_found )
    {
        for( auto elem : m )
        {
            if( elem.second < 0 )
            {
                cout << elem.first;
                break;
            }
        }
    }


    return 0;
}
