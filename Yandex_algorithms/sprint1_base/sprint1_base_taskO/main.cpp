#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

typedef unsigned short UShort;

bool IsAnagram( const string &str, unordered_multiset<char> pattern_set )
{
    bool result = true;

    for( char c : str )
    {
        if( pattern_set.find( c ) != pattern_set.end() )
        {
            pattern_set.erase( c );
        }
        else
        {
            result = false;
            break;
        }
    }

    if( pattern_set.size() != 0 )
        result = false;

    return result;
}

int main()
{
    string input;
    getline( cin, input );

    string pattern;
    getline( cin, pattern );

    // представляем шаблон в виде множества его символов
    unordered_multiset<char> pattern_set;
    for( char c : pattern )
        pattern_set.insert( c );

    UShort ind_beg = 0; // индекс начала рассматриваемого "окна"
    UShort ind_end = pattern.size() - 1; // индекс конца рассматриваемого "окна"
    UShort anagrams_counter = 0;
    while( ind_end < input.size() )
    {
        if( IsAnagram( input.substr( ind_beg, ind_end - ind_beg + 1 ), pattern_set ) )
            ++anagrams_counter;
        ++ind_beg;
        ++ind_end;
    }

    cout << anagrams_counter;

    return 0;
}
