#include <iostream>
#include <string>
#include <locale>
#include <set>

using namespace std;

int main()
{
    // считываем фразу
    string phrase;
    getline( cin, phrase );

    // будем двигаться по фразе от начала и конца к середине и сравнивать соответствующие символы
    bool answer = true;
    size_t forw_ind = 0;
    size_t backw_ind = phrase.size() - 1;

    set<char> comparable{ 'A', 'B', 'B', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                          'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                          'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
                          '4', '5', '6', '7', '8', '9' };

    while( forw_ind < backw_ind )
    {
        // пропускаем прочие символы
        if( comparable.find( toupper( phrase[ forw_ind ] ) ) == comparable.end() )
        {
            ++forw_ind;
            continue;
        }
        if( comparable.find( toupper( phrase[ backw_ind ] ) ) == comparable.end() )
        {
            --backw_ind;
            continue;
        }

        // как только нашли несовпадающую пару символов, заканчиваем работу
        if( toupper( phrase[ forw_ind ] ) != toupper( phrase[ backw_ind ] ) )
        {
            answer = false;
            break;
        }
        // если символы совпадают, двигаемся дальше
        else
        {
            ++forw_ind;
            --backw_ind;
        }
    }

    if( answer )
        cout << "True";
    else
        cout << "False";

    return 0;
}
