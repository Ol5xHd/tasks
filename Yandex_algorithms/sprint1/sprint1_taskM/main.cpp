#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Letter
{
    char mValue; // собственно буква
    unsigned short mCount; // количество её вхождений в слово
};

int main()
{
    // читаем входное слово
    string input;
    getline( cin, input );

    // в мапе будем хранить количество вхождений по буквам
    map<char, unsigned short> counts;
    for( char c : input )
    {
        if( counts.find( c ) == counts.end() )
            counts.emplace( c, 1 );
        else
            counts[ c ] += 1;
    }

    // в векторе будет список всех встречавшихся букв
    vector<char> letters;
    for( auto elem : counts )
        letters.push_back( elem.first );

    // сортируем вектор букв по частоте вхождения
    sort( letters.begin(), letters.end(), [ &counts ]( const char &left, const char &right ) {
        if( left == right )
            return left < right;
        else
            return counts[ left ] > counts[ right ];
    } );

    // выводим результат
    for( char c : letters )
        for( unsigned short count = 0; count < counts[ c ]; ++count )
            cout << c;

    return 0;
}
