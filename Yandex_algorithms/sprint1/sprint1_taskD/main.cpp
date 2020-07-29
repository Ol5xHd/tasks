#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string line;

    // читаем количество чисел
    getline( cin, line );
    unsigned int n = static_cast<unsigned int>( stoi( line ) );

    // читаем очки за все дни
    getline( cin, line );
    stringstream sstream( line );
    vector<int> points( n );
    for( int number, ind = 0; sstream >> number; ++ind )
        points[ ind ] = number;

    unsigned int zero_ind = 0; // индекс первого по порядку нуля
    bool zero_found = false; // флаг, встретился ли ноль при просмотре массива
    // просматриваем каждый элемент массива, будем менять местами нулевые элементы с ненулевыми
    for( unsigned int i = 0; i < points.size(); ++i )
    {
        if( points[ i ] == 0 )
        {
            if( !zero_found )
            {
                // если встретили ноль, и это первый ноль, то запоминаем его позицию и взводим флаг
                zero_ind = i;
                zero_found = true;
            }
            // если это не первый ноль, то идём дальше в поисках ненулевого элемента
        }
        else
        {
            if( zero_found )
            {
                // если встретили не-ноль, и до этого  встречался ноль, то меняем местами эти два значения
                points[ zero_ind ] = points[ i ];
                points[ i ] = 0;

                // сбрасываем флаг и продолжаем поиск с той позиции, куда перенесли не-ноль
                zero_found = false;
                i = zero_ind;
            }
        }
    }

    // если ни одного нуля не встретили, то будем выводить в результат весь исходный массив
    if( !zero_found )
        zero_ind = points.size();
    // но в общем случае выводим результат до первого нулевого жлемента, чей индекс нам известен
    for( unsigned int i = 0; i < zero_ind; ++i )
        cout << points[ i ] << ' ';

    return 0;
}
