/**
 * Махов Александр, Алгоритмы, Когорта 03
 * спринт 2, задача A. Фотокопии
 * ID успешной посылки - 33822308
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;
typedef unsigned long long ULLong;

// метод подсчёта максимальной вместимости группы датацентров, по два центра на фотографию
// реализация стратегии 4 из примечаний к задаче
// centers - вместимости датацентров
// возвращает максимальную вместимость
ULLong maxCapacity( vector<UShort> &centers ) {
    // итераторы, которые будут указывать на центры с минимальной и максимальной вместимостью
    vector<UShort>::iterator it_min = centers.end();
    vector<UShort>::iterator it_max = centers.end();

    // лямбда для подготовки вектора к следующему шагу алгоритма; поиск центров
    auto find_min_max = [ &centers, &it_min, &it_max ] () {
        it_min = centers.end();
        it_max = centers.end();
        for( auto it = centers.begin(); it != centers.end(); ++it ) {
            if( *it > 0 ) {
                if( it_max == centers.end() || *it > *it_max )
                    it_max = it;
                if( it_min == centers.end() || *it <= *it_min )
                    it_min = it;
            }
        }
    };

    ULLong max_capacity = 0;
    // на каждом шаге помещаем одну фотографию в два центра - с максимальной и минимальной вместимостью
    find_min_max();
    while( it_min != it_max ) {
        max_capacity += 1;
        *it_min -= 1;
        *it_max -= 1;
        find_min_max();
    }

    return max_capacity;
}

int main() {
    string input_line = "";

    // читаем количество датацентров
    getline( cin, input_line );
    UShort centers_cnt = static_cast<UShort>( stoi( input_line ) );

    // на всякий случай обработаем нулевое количество датацентров
    if( centers_cnt > 0 ) {
        // читаем вместимости датацентров
        getline( cin, input_line );
        stringstream input_sstream( input_line );
        vector<UShort> centers( centers_cnt );
        for( UShort i = 0; i < centers_cnt; ++i )
            input_sstream >> centers[ i ];

        cout << maxCapacity( centers );
    }
    else {
        cout << 0;
    }

    return 0;
}
