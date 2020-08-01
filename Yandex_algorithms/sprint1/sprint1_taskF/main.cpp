#include <iostream>
#include <string>
#include <sstream>
#include <array>

using namespace std;

typedef unsigned short UShort;

const UShort MAX_NUMBER = 10000;

int main()
{
    string line;

    // читаем количество чисел n
    getline( cin, line );
    UShort n = static_cast<UShort>( stoi( line ) );

    // читаем строку с числами
    getline( cin, line );
    stringstream sstream( line );

    // заведём массив, где индексом будет значение числа, а внутри будет хранить флаг, встретилось ли число
    array<bool, MAX_NUMBER + 1> all_numbers = { false };
    for( UShort number; sstream >> number; )
    {
        if( all_numbers[ number ] )
        {
            cout << number;
            break;
        }
        else
        {
            all_numbers[ number ] = true;
        }
    }

    return 0;
}
