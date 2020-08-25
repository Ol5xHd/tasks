/**
 * Махов Александр, Алгоритмы, Когорта 03
 * спринт 2, задача B. Поиск в сломанном массиве
 * ID успешной посылки - 33822316
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned short UShort;

short findRecursive( const vector<UShort> &elems, UShort target_val, UShort beg_ind, UShort end_ind );

// вспомогательный метод для findRecursive - ищет элемент в отрезках [sorted_beg, sorted_end] и [another_beg, another_end]
// если элемент в сортированной части, ищет по ней, иначе переводит поиск в другую часть
short findInPartition( const vector<UShort> elems, UShort target_val, UShort sorted_beg, UShort sorted_end, UShort another_beg, UShort another_end ) {
    if( elems[ sorted_beg ] <= target_val && target_val <= elems[ sorted_end ] ) { // искомый элемент в сортированной части
        return findRecursive( elems, target_val, sorted_beg, sorted_end );
    }
    else { // искомый элемент в другой части
        if( another_beg <= another_end ) { // другая часть существует
            return findRecursive( elems, target_val, another_beg, another_end );
        }
    }

    return -1;
}

// рекурсивный метод поиска элемента в массиве, ищет в отрезке [beg_ind, end_ind]
// elems - массив
// target_val - искомое значение
// beg_ind - индекс начала отрезка для поиска
// end_ind - индекс конца отрезка для поиска
// возвращает индекс искомого элемента в массиве, если он там есть, а иначе -1
short findRecursive( const vector<UShort> &elems, UShort target_val, UShort beg_ind, UShort end_ind ) {
    UShort center_ind = ( end_ind + beg_ind ) / 2; // ищем центр отрезка
    if( elems[ center_ind ] == target_val ) { // нашли искомый элемент - возвращаем
        return static_cast<short>( center_ind );
    }
    else { // не нашли, будем искать в левой и правой частях массива относительно центрального элемента
        // вычислим соответствующие индексы начала и конца левой и правой частей
        UShort left_beg = beg_ind;
        UShort left_end = center_ind - 1;
        UShort right_beg = center_ind + 1;
        UShort right_end = end_ind;

        // после разделения исходного массива центральным элементом на два подмассива - одна из частей обязательно будет упорядочена
        // будем искать элемент в упорядоченной части, т.к. там достаточно только проверить границы
        // если элемент в упорядоченной части, то продолжаем поиск внутри неё, иначе переводим поиск в другую часть
        if( left_beg <= left_end && elems[ left_beg ] <= elems[ left_end ] ) { // левая часть существует и упорядочена
            return findInPartition( elems, target_val, left_beg, left_end, right_beg, right_end );
        }
        else if( right_beg <= right_end && elems[ right_beg ] <= elems[ right_end ] ) { // правая часть существует и упорядочена
            return findInPartition( elems, target_val, right_beg, right_end, left_beg, left_end );
        }
    }

    return -1;
}

// основной метод поиска элемента в сломанном массиве; скрывает рекурсивную реализацию от пользователя
// elems - массив
// target_val - искомый элемент
// возвращает индекс искомого элемента в массиве, если он там есть, а иначе -1
short Find( const vector<UShort> &elems, UShort target_val ) {
    UShort beg_ind = 0;
    UShort end_ind = static_cast<UShort>( elems.size() - 1 );

    return findRecursive( elems, target_val, beg_ind, end_ind );
}

int main() {
    string input_line = "";

    // читаем длину массива
    getline( cin, input_line );
    UShort arr_length = static_cast<UShort>( stoi( input_line ) );

    // читаем искомый элемент
    getline( cin, input_line );
    UShort target_val = static_cast<UShort>( stoi( input_line ) );

    // читаем массив
    getline( cin, input_line );
    stringstream input_sstream( input_line );
    vector<UShort> elems( arr_length );
    for( UShort i = 0 ; i < arr_length; ++i )
        input_sstream >> elems[ i ];

    cout << Find( elems, target_val );

    return 0;
}
