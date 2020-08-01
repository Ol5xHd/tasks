#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned short UShort;

int main()
{
    // читаем первый массив, сразу раскладываем в вектор
    string line;
    getline( cin, line );
    stringstream sstream( line );
    vector<UShort> first;
    for( UShort id; sstream >> id; )
        first.push_back( id );

    getline( cin, line ); // читаем количество не-нулей в первом массиве, нам эта информация не нужна
    getline( cin, line ); // читаем количество электов во втором массиве, нам эта информация не нужна
    getline( cin, line ); // читаем второй массив
    // и тоже сразу раскладываем в вектор
    sstream.clear();
    sstream.str( line );
    vector<UShort> second;
    for( UShort id; sstream >> id; )
        second.push_back( id );

    // бежим по второму массиву айдиников, надо их вставить в первый массив
    for( UShort id : second )
    {
        // для каждого айдишника из второго массива ищем место в первом
        for( size_t i = 0; i < first.size(); ++i )
        {
            if( first[ i ] == 0 )
            {
                // встретили ноль, можно спокойно вместо него писать наш айдишник
                first[ i ] = id;
                break;
            }
            else if( id >= first[ i ] )
            {
                // пролистываем все айдишники, меньшие или равные нашему
                continue;
            }
            else
            {
                // нашли позицию для нашего айдишника
                // надо сдвинуть весь "хвост" вправо от позиции вставки
                for( size_t j = first.size() - 1; j > i; --j )
                    first[ j ] = first[ j - 1 ];

                // теперь можем записать наш айдишник
                first[ i ] = id;
                break;
            }
        }
    }

    for( UShort elem : first )
        cout << elem << ' ';

    return 0;
}
