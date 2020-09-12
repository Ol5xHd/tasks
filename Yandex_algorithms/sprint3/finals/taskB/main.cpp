/**
 * Махов Александр, Алгоритмы, Когорта 03
 * спринт 3, задача B. Золотая середина
 * ID успешной посылки - 34156919
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned short UShort;

// метод вычисляет медиану массива
double medianVal( vector<UShort> _vector ) {
    if( _vector.size() % 2 == 0)
        return ( _vector[ _vector.size() / 2 - 1 ] + _vector[ _vector.size() / 2 ] ) / 2.;
    else
        return static_cast<double>( _vector[ _vector.size() / 2 ] );
}

// вспомогательный метод для проверки, что медиана найдена
bool XLeftLessYRight( vector<UShort> &X, size_t X_left_size, vector<UShort> &Y, size_t Y_left_size ) {
    if( X_left_size == 0 || Y_left_size == Y.size() )
        return true;
    else
        return X[ X_left_size - 1 ] <= Y[ Y_left_size ];
}

// вспомогательный метод для проверки, что медиана найдена
bool YLeftLessXRight( vector<UShort> &X, size_t X_left_size, vector<UShort> &Y, size_t Y_left_size ) {
    if( X_left_size == X.size() || Y_left_size == 0 )
        return true;
    else
        return Y[ Y_left_size - 1 ] <= X[ X_left_size ];
}

UShort maxLeft( vector<UShort> &X, size_t X_left_size, vector<UShort> &Y, size_t Y_left_size ) {
    // одновременно X_left_size и Y_left_size не могут быть равны 0
    if( X_left_size == 0 )
        return Y[ Y_left_size - 1 ];
    else if( Y_left_size == 0 )
        return X[ X_left_size - 1 ];
    else
        return max( X[ X_left_size - 1], Y[ Y_left_size - 1 ] );
}

UShort minRight( vector<UShort> &X, size_t X_left_size, vector<UShort> &Y, size_t Y_left_size ) {
    // одновременно X_left_size и Y_left_size не могут быть равны длинам соответствующих массивов
    if( X_left_size == X.size() )
        return Y[ Y_left_size ];
    else if( Y_left_size == Y.size() )
        return X[ X_left_size ];
    else
        return min( X[ X_left_size ], Y[ Y_left_size ] );
}

// основная рекурсивная реализация алгоритма поиска медианы двух массивов
// X, Y - первый и второй массивы
// X_beg, X_end - индексы начала и конца подотрезка в X, на котором ищем медиану
// X_left_size - количество элементов в левой части X
double calculateMedianImpl( vector<UShort> &X, vector<UShort> &Y, size_t X_beg, size_t X_end, size_t X_left_size ) {
    // будем делить массивы X и Y на две части - левую и правую - таким образом,
    // чтобы |X_left| + |Y_left| == |X_right| + |Y_right| или |X_left| + |Y_left| == |X_right| + |Y_right| + 1 (в случае нечётной суммы)

    size_t Y_left_size = ( X.size() + Y.size() + 1 ) / 2 - X_left_size; // размер левого подмассива массива Y
    UShort max_left = maxLeft( X, X_left_size, Y, Y_left_size ); // максимальный элемент в X_left и Y_left
    UShort min_right = minRight( X, X_left_size, Y, Y_left_size ); // минимальный элемент из X_right и Y_right

    // нашли медиану двух массивов, если выполнены два условия
    // 1) максимальный элемент из X_left <= минимального из Y_right
    // 2) максимальный элемент из Y_left <= минимального из X_right
    // тогда все элементы левой части разбиения <= элементов правой части, а количества их совпадают с точностью до 1 элемента
    if( XLeftLessYRight( X, X_left_size, Y, Y_left_size ) && YLeftLessXRight( X, X_left_size, Y, Y_left_size ) ) {
        if( ( X.size() + Y.size() ) % 2 == 0 )
            return ( max_left + min_right ) / 2.0;
        else
            return static_cast<double>( max_left );
    }
    else { // медиана не найдена, необходимо сместить разбиение
        if( X[ X_left_size - 1 ] > Y[ Y_left_size ] ) { // надо сместить разбиение первого массива влево
            X_end -= ( X_end - X_beg + 1 ) / 2; // вдвое укорачиваем отрезок, на котором ищем медиану
            X_left_size = ( X_beg + X_end + 1 ) / 2; // в конце концов размер левой части будет 0 при X_beg == X_end
        }
        else { // надо сместить разбиение первого массива вправо
            X_beg += ( X_end - X_beg + 1 ) / 2; // вдвое укорачиваем отрезок, на котором ищем медиану
            X_left_size = ( X_beg + X_end) / 2 + 1; // в конце концов размер левой части будет X.size() при X_beg == X_end == X.size() - 1
        }
    }

    return calculateMedianImpl( X, Y, X_beg, X_end, X_left_size ); // рекурсивно продолжаем поиск на вдвое меньшем отрезке
}

// функция поиска медианы двух массивов - внешняя обёртка для пользователя
// X - первый массив
// Y - второй массив
// возвращает значение медианы
double calculateMedian( vector<UShort> &X, vector<UShort> &Y ) {
    if( X.size() == 0 && Y.size() == 0 ) { // оба массива пустые
        return 0;
    }

    if( X.size() > Y.size() ) // для алгоритма важно, чтобы первый массив был не больше второго по размеру
        return calculateMedian( Y, X );

    // если один из массивов пуст, ответом на задачу будет медиана второго массива
    if( X.size() == 0 ) {
        return medianVal( Y );
    }
    if( Y.size() == 0 ) {
        return medianVal( X );
    }

    return calculateMedianImpl( X, Y, 0, X.size() - 1, ( X.size() + 1 ) / 2 ); // вызов основного алгоритма
}

int main() {
    string line;

    getline( cin, line );
    size_t N = static_cast<size_t>( stoi( line ) ); // длина первого массива

    getline( cin, line );
    size_t M = static_cast<size_t>( stoi( line ) ); // длина второго массива

    getline( cin, line );
    stringstream in_sstream( line );
    vector<UShort> X( N ); // первый массив
    for( size_t i = 0; i < N; ++i )
        in_sstream >> X[ i ];

    getline( cin, line );
    in_sstream.clear();
    in_sstream.str( line );
    vector<UShort> Y( M ); // второй массив
    for( size_t i = 0; i < M; ++i )
        in_sstream >> Y[ i ];

    cout << calculateMedian( X, Y ); // вычисление и вывод ответа

    return 0;
}
