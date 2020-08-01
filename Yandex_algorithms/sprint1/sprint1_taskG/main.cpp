#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    // считываем слово 1
    string word1;
    getline( cin, word1 );

    // считываем слово 2
    string word2;
    getline( cin, word2 );

    // переводим слова в мультисеты
    multiset<char> set1;
    for( char c : word1 )
        set1.insert( c );
    multiset<char> set2;
    for( char c : word2 )
        set2.insert( c );

    // если мультисеты равны, то это анаграммы
    if( set1 == set2 )
        cout << "True";
    else
        cout << "False";

    return 0;
}
