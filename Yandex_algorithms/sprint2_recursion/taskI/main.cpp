#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <map>

using namespace std;

typedef unsigned short UShort;
typedef unsigned int UInt;

/**
 * @brief основной метод перебора комбинаций монеток
 * @param coins - множество монеток, из которого выбираем
 * @param combinations - множество комбинаций монеток (по числу победителей)
 * @param curr_ind - индекс текущего множества, которое пытаемся сформировать
 * @param target_sum - сумма для каждого победителя
 * @param winners_cnt - число победителей
 * @return true, если разделить можно, иначе false
 */
bool Combine( multiset<UShort> coins, map<UShort, multiset<UShort>> &combinations, UShort curr_ind, UInt target_sum, UShort winners_cnt )
{
    multiset<UShort> &curr_comb = combinations[ curr_ind ];
    UInt curr_sum = 0;
    for( const UShort &coin : curr_comb )
        curr_sum += coin;
    if( curr_sum == target_sum ) // в текущем множестве сформировалась нужная сумма
    {
        ++curr_ind; // это множество сформировано, занимаемся следующим
        if( curr_ind == winners_cnt ) // а нет следующего множества, сформировали для всех победителей
        {
            if( coins.empty() ) // да ещё и все монетки потратили
                return true; // ну это успех
            else // оп-па, лишние монетки остались
                return false; // фиаско
        }
        else // есть следующее множество. которое надо сформировать
        {
            return Combine( coins, combinations, curr_ind, target_sum, winners_cnt );
        }
    }
    else if( curr_sum < target_sum ) // в текущем множестве недостаточная сумма
    {
        if( coins.empty() ) // но основной пул монеток пуст, не из чего выбирать
        {
            return false;
        }
        else // есть ещё монетки для выбора
        {
            for( auto it = coins.begin(); it != coins.end(); ++it ) // каждую монетку из оставшихся попробуем пристроить в текущее множество
            {
                if( *it > target_sum - curr_sum ) // если с монеткой сумма станет слишком большой, пропустим её
                {
                    continue;
                }
                else // монетка сумму нам не испортит, хорошо
                {
                    curr_comb.insert( *it ); // добавляем её
                    multiset<UShort> new_coins; // сформируем новый пул монеток - без одной, которую только что использовали
                    for( auto sub_it = coins.begin(); sub_it != coins.end(); ++sub_it )
                        if( sub_it != it )
                            new_coins.insert( *sub_it );
                    bool sub_res = Combine( new_coins, combinations, curr_ind, target_sum, winners_cnt );
                    if( sub_res ) // такой расклад привёл к успеху
                        return true;
                    else // расклад не привёл к успеху
                        curr_comb.erase( *it ); // вынимаем монетку из текущего множества
                }
            }
        }
        return false; // перебрали все монетки, но успеха не достигли - фиаско
    }
    else if( curr_sum > target_sum ) // в текущем множестве слишком большая сумма, нельзя так
    {
        return false;
    }

    return false; // на всяский случай - не должны этой точки достичь
}

bool CanShare( multiset<UShort> &coins, UShort winners_cnt )
{
    UInt total_sum = 0;
    for( const UShort &coin : coins )
        total_sum += coin;

    if( total_sum % winners_cnt != 0 )
        return false;

    UInt target_sum = total_sum / winners_cnt;
    map<UShort, multiset<UShort>> combinations; // здесь будем хранить все комбинации монеток для победителей
    for( UShort i = 0; i < winners_cnt; ++i )
        combinations.insert( pair<UShort, multiset<UShort>>( i, multiset<UShort>() ) );
    UShort curr_ind = 0;

    return Combine( coins, combinations, curr_ind, target_sum, winners_cnt );
}

int main()
{
    ifstream fin;
    fin.open( "input.txt" );

    string line;

    getline( fin, line );
    UShort winners_cnt = static_cast<UShort>( stoi( line ) );

    getline( fin, line );
    UShort coins_cnt = static_cast<UShort>( stoi( line ) );

    getline( fin, line );
    stringstream sstream( line );
    multiset<UShort> coins;
    for( UShort i = 0; i < coins_cnt; ++i )
    {
        UShort coin = 0;
        sstream >> coin;
        coins.insert( coin );
    }

    bool can_share = CanShare( coins, winners_cnt );
    if( can_share )
        cout << "True";
    else
        cout << "False";

    return 0;
}
