#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string line;

    getline( cin, line );
    unsigned short N = static_cast<unsigned short>( stoi( line ) );

    getline( cin, line );
    stringstream sstream( line );
    vector<unsigned short> numbers( N );
    for( size_t i = 0; i < N; ++i )
        sstream >> numbers[ i ];

    bool splitting_exists = false;

    // сначала посчитаем сумму всех чисел
    unsigned long total_sum = 0;
    for( unsigned short n : numbers )
        total_sum += n;

    // если общая сумма нечётная, то разбиение на равные суммы невозможно
    // если сумма чётная, то пробуем построить разбиение методом динамического программирования
    if( total_sum % 2 == 0 )
    {
        unsigned long target_sum = total_sum / 2;

        // строим таблицу, где индекс столбца - это количество рассматриваемых элементов из изначального множества [0..N]
        // индекс строки - это целевая сумма [0..target_sum]
        bool** matrix = new bool*[ target_sum + 1 ];
        for( unsigned long i = 0; i < target_sum + 1; ++i )
            matrix[ i ] = new bool[ N + 1 ];

        // заполняем первый столбец таблицы
        // из множества нулевой длины получить нулевую сумму можно всегда
        matrix[ 0 ][ 0 ] = true;
        // а вот ненулевую сумму - никогда
        for( unsigned long i = 1; i < target_sum + 1; ++i )
            matrix[ i ][ 0 ] = false;

        // далее заполняем все оставшиеся столбцы по очереди
        for( unsigned short i = 0; i <= target_sum; ++i ) // цикл по целевым суммам
        {
            for( unsigned long j = 1; j <= N; ++j ) // цикл по числу элементов из подмножества
            {
                // если слева в таблице уже стоит true, то в данной ячейке тоже будет true,
                // т.к. из большего подмножества нам надо получить ту же сумму, что всегда возможно
                matrix[ i ][ j ] = matrix[ i ][ j - 1 ];

                bool leeft = matrix[ i ][ j - 1 ]; // Debug

                // если в предыдущем столбце была достигнута сумма = ( i - j-ый элемент ),
                // то в текущей ячейке тоже ставим true
                if( i >= numbers[ j - 1 ] )
                {
                    bool prev =  matrix[ i - numbers[ j - 1 ] ][ j - 1 ]; // Debug
                    matrix[ i ][ j ] = matrix[ i ][ j ] || matrix[ i - numbers[ j - 1 ] ][ j - 1 ];
                }
            }
        }

        // в нижней-правой ячейке нашей таблицы находится ответ, можно ли получить полусумму из какого-то помножества вхожных элементов
        // если полусумма получается, то другая часть входного множества автоматически даётся вторую полусумму, т.е. разбиение построить можно
        if( matrix[ target_sum ][ N ] )
            splitting_exists = true;
    }

    if( splitting_exists )
        cout << "True";
    else
        cout << "False";

    return 0;
}
