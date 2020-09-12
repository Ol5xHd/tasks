/**
 * Махов Александр, Алгоритмы, Когорта 03
 * спринт 3, задача A. Большое число
 * ID успешной посылки - 34114387
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

    // лямбда сравнения двух строк одинаковой длины, возвращает true, если left > right
    // можно было бы обойтись и стандартной перегрузкой ператора > для строк, но реализовал свой вариант для наглядности
    auto leftBiggerThanRight = []( const string &left, const string &right ) -> bool {
        bool left_bigger = false;
        for( size_t i = 0; i < left.size(); ++i ) {
            if( left[ i ] > right[ i ] ) {
                left_bigger = true;
                break;
            }
            else if( left[ i ] < right[ i ] ) {
                break;
            }
        }
        return left_bigger;
    };

    // упорядочим числа в векторе таким образом, чтобы два любых числа при последовательной записи давали наибольший результат
    sort( numbers.begin(), numbers.end(), [ &leftBiggerThanRight ]( const string &left, const string &right ) {
        // если строка AB > строки BA, то тогда считаем, что A > B
        // эта метрика обладает транзитивностью, т.е. A > B > C => A > C, но доказать это я не могу)))
        string left_right = left + right;
        string right_left = right + left;
        // упорядочиваем по убыванию, т.к. хотим максимизировать результат
        return leftBiggerThanRight( left_right, right_left ); // left_right > right_left => left > right
    } );

    for( auto it : numbers )
        cout << it;

    return 0;
}
