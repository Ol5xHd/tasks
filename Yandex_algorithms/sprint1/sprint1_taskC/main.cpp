#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;

/**
 * @brief функция перевода числа в списочную форму
 * @param number - исходное число
 * @param list_form - списочная форма
 */
void NumberToListForm( UShort number, vector<UShort> &list_form )
{
    if( number == 0 )
    {
        list_form.push_back( 0 );
        return;
    }

    while( number > 0 )
    {
        list_form.push_back( number % 10 );
        number /= 10;
    }
    reverse( list_form.begin(), list_form.end() );
}

/**
 * @brief функция сложения двух списочных форм
 * @param left - левое слагаемое в списочной форме
 * @param right - правое слагаемое в списочной форме
 * @param sum - результат в списочной форме
 */
void AddTwoListForms( vector<UShort> &left, vector<UShort> &right, vector<UShort> &sum )
{
    // удобно складывать два числа, начиная с меньших разрядов, поэтому развернём списочные формы
    reverse( left.begin(), left.end() );
    reverse( right.begin(), right.end() );

    // одно из чисел может быть длиннее, "добьём" короткое нулями
    UShort left_length = left.size();
    UShort right_length = right.size();
    if( left_length > right_length )
        right.insert( right.end(), left_length - right_length, 0 );
    else if( right_length > left_length )
        left.insert( left.end(), right_length - left_length, 0 );

    UShort memory = 0; // "излишек" при сложении разрядов, число "в уме"
    // основной цикл сложения двух чисел, сложение по разрядам
    for( auto i = 0; i < left.size(); ++i )
    {
        UShort sub_sum = left[ i ] + right[ i ] + memory;
        if( sub_sum > 9 )
        {
             sum.push_back( sub_sum % 10 );
             memory = 1;
        }
        else
        {
            sum.push_back( sub_sum );
            memory = 0;
        }
    }
    if( memory > 0 )
        sum.push_back( 1 );

    reverse( sum.begin(), sum.end() );
}

int main()
{
    string line;

    // читаем длину списочной формы числа X
    getline( cin, line );
    UShort X_numbers_count = static_cast<UShort>( stoi( line ) );

    // читаем списочную форму числа X
    getline( cin, line );
    stringstream sstream( line );
    vector<UShort> X_list_form( X_numbers_count );
    for( UShort number, ind = 0; sstream >> number; ++ind )
        X_list_form[ ind ] = number;

    // читаем число K
    getline( cin, line );
    UShort K = static_cast<UShort>( stoi( line ) );

    // переводим число K в списочную форму
    vector<UShort> K_list_form;
    NumberToListForm( K, K_list_form );

    // списочная форма суммы чисел
    vector<UShort> SUM_list_form;
    AddTwoListForms( X_list_form, K_list_form, SUM_list_form );

    for( auto elem : SUM_list_form )
        cout << elem << ' ';

    return 0;
}
