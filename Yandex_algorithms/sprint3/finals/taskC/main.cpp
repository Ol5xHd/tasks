/**
 * Махов Александр, Алгоритмы, Когорта 03
 * спринт 3, задача C. Radix Sort
 * ID успешной посылки - 34264629
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

typedef unsigned long ULong;
typedef unsigned short UShort;

// функция, осуществляющая порязрядную сортировку вектора чисел
// original - вектор дял сортировки
void radixSort( vector<ULong> &original ) {
    vector<ULong> copy( original ); // копия исходного вектора, где на каждом шагу элементы будут уменьшаться делением на 10
    vector<size_t> indexes( original.size() ); // вектор индексов элементов
    for( size_t i = 0; i < indexes.size(); ++i )
        indexes[ i ] = i;

    // основнйо цикл сортировки - сортировать будем не сами элементы, а их индексы
    bool all_zeroes = false; // флаг завершения алгоритма
    while( !all_zeroes ) { // как только все элементы стали нулевыми, сортировку можно останавливать
        all_zeroes = true;

        // разбиваем всё множество элементов на группы по k-ой цифре (справа-налево)
        map<UShort, vector<size_t>> groups;
        for( size_t i = 0; i < indexes.size(); ++i ) {
            if( copy[ indexes[ i ] ] != 0 ) // не забываем взвести флаг, что ещё не все элементы нулевые
                all_zeroes = false;
            UShort curr_digit = copy[ indexes[ i ] ] % 10;
            auto it = groups.find( curr_digit );
            if( it == groups.end() )
                groups.emplace( curr_digit, vector<size_t>{ i } );
            else
                it->second.push_back( i );
            copy[ indexes[ i ] ] /= 10;
        }

        if( all_zeroes ) // все нули, дальше можно не сортировать
            break;

        // создаём новый массив индексов, где упорядочиваем их в зависимости от k-ой цифры в соответствующем элементе исходного массива
        vector<size_t> new_indexes( indexes.size() );
        size_t ind_it = 0;
        for( UShort i = 0; i < 10; ++i ) {
            auto it = groups.find( i );
            if( it != groups.end() ) {
                for( size_t ind : it->second ) {
                    new_indexes[ ind_it ] = indexes[ ind ];
                    ++ind_it;
                }
            }
        }
        indexes.swap( new_indexes ); // новый массив индексов на следующем шаге будет исходным
    }

    // заполняем вектор-копию исходными элементами, но уже в отсортированном порядке
    size_t ind_it = 0;
    for( size_t ind : indexes ) {
        copy[ ind_it ] = original[ ind ];
        ++ind_it;
    }
    original.swap( copy ); // содержимое копии стало исходным массивом
}

int main() {
    string line;

    getline( cin, line );
    ULong N = static_cast<ULong>( stoi( line ) ); // считываем длину входного массива

    getline( cin, line );
    stringstream in_sstream( line );
    vector<ULong> elems( N );
    for( size_t i = 0; i < N; ++i ) // считываем входной массив
        in_sstream >> elems[ i ];

    radixSort( elems ); // зовём поразрядную сортировку

    for( ULong it : elems ) // выводим результат
        cout << it << ' ';

    return 0;
}
