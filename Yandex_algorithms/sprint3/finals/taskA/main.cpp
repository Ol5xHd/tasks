/**
 * Махов Александр, Алгоритмы, Когорта 03
 * спринт 3, задача A. Большое число
 * ID успешной посылки - 34028291
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;

int main() {
    string line; // буфер для входных данных

    getline( cin, line );
    UShort count = static_cast<UShort>( stoi( line ) ); // количество чисел

    getline( cin, line );
    stringstream in_sstream( line );
    vector<string> numbers( count ); // вектор с числами
    for( UShort i = 0; i < count; ++i )
        in_sstream >> numbers[ i ];

    // упорядочим числа в векторе таким образом, чтобы два любых числа при последовательной записи давали наибольший результат
    sort( numbers.begin(), numbers.end(), []( const string &left, const string &right ) {
        // если строка AB > строки BA, то тогда считаем, что A > B
        // эта метрика обладает транзитивностью, т.е. A > B > C => A > C, но доказать это я не могу)))
        string left_right = left + right;
        string right_left = right + left;
        // упорядочиваем по убыванию, т.к. хотим максимизировать результат
        if( left_right > right_left ) // => left > right
            return true;
        else
            return false;
    } );

    for( auto it : numbers )
        cout << it;

    return 0;
}
