#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;

void AddTwoNumbers( vector<UShort> &left, vector<UShort> &right, vector<UShort> &sum )
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
        if( sub_sum > 1 )
        {
             sum.push_back( sub_sum % 2 );
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

    // считываем первое число
    getline( cin, line );
    vector<unsigned short> number1( line.size(), 0 );
    for( auto i = 0; i < line.size(); ++i )
        number1[ i ] = line[ i ] == '0' ? 0 : 1;

    // считываем второе число
    getline( cin, line );
    vector<unsigned short> number2( line.size(), 0 );
    for( auto i = 0; i < line.size(); ++i )
        number2[ i ] = line[ i ] == '0' ? 0 : 1;

    vector<unsigned short> sum;
    AddTwoNumbers( number1, number2, sum );
\
    for( auto elem : sum )
        cout << elem;

    return 0;
}
