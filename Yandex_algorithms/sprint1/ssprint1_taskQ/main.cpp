#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;



int main()
{
    // считываем количество чисел
    string line;
    getline( cin, line );
    short N = static_cast<short>( stoi( line ) );

    // считываем все числа
    getline( cin, line );
    stringstream sstream( line );
    vector<short> points( N );
    for( short number, ind = 0; sstream >> number; ++ind )
        points[ ind ] = number;

    // отсортируем исходный массив, чтобы с ним легче было работать
    sort( points.begin(), points.end() );

    long best_mult = -1; // лучшее произведение, которое удалось найти
    // для каждого элеента массива будем искать пару, которые вместе с ним дают в сумме ноль
    for( size_t i = 0; i < points.size(); ++i )
    {
        size_t forward_ind = 0; // индекс от начала массива
        size_t backward_ind = points.size() - 1; // от конца
        // будем их двигать навстречу друг другу
        while( forward_ind < backward_ind )
        {
            if( forward_ind == i )
            {
                ++forward_ind;
                continue;
            }
            if( backward_ind == i )
            {
                --backward_ind;
                continue;
            }

            short sum = points[ i ] + points[ forward_ind ] + points[ backward_ind ];
            if( sum > 0 )
            {
                // сумма больше, чем надо -> уменьшаем большее слагаемое
                --backward_ind;
                continue;
            }
            else if( sum < 0 )
            {
                // увеличиваем меньшее слагаемое
                ++forward_ind;
                continue;
            }
            else
            {
                // нашли нулевую сумму
                long curr_mult = points[ i ] * points[ forward_ind ] * points[ backward_ind ];
                // усли произведение лучше уже имеющегося, то запомним его
                if( curr_mult > best_mult )
                    best_mult = curr_mult;
                ++forward_ind;
            }
        }
    }

    cout << best_mult;

    return 0;
}
