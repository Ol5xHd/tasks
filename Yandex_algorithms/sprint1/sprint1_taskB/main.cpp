#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <array>
#include <iostream>

using namespace std;

typedef unsigned short UShort; // просто для удобства

const UShort MAX_UNIVERSITY_ID = 10000; // из условия задачи

int main()
{
    string line;

    // читаем список id вузов
    getline( cin, line );
    istringstream iss( line );
    vector<string> ids{ istream_iterator<string>{ iss }, istream_iterator<string>{} };

    // читаем количество вузов для результата
    getline( cin, line );
    UShort result_length = static_cast<UShort>( stoi( line ) );

    // массив всех университетов, где индекс ячейки = id университета
    // MAX_UNIVERSITY_ID + 1, т.к. индекс ячейки на 1 меньше порядкового номера ячейки
    array<UShort, MAX_UNIVERSITY_ID + 1> universities{ 0 };
    for( const string &id : ids )
    {
        UShort university_id = static_cast<UShort>( stoi( id ) );
        universities[ university_id ] += 1;
    }

    UShort min_university_id = 0; // id наименее представленного университета, позже пргодится для формирования результата
    for( UShort i = 0; i < universities.size(); ++i )
        if( universities[ i ] < universities[ min_university_id ] )
            min_university_id = i;

    // вектор ответов, в нём будем хранить id самых представленных университетов
    // по умолчанию заполняем массив идентификатором наименее представленного университета, чтобы любой другой мог его "выдавить" из ответа
    vector<UShort> answer( result_length, min_university_id );
    for( UShort i = 0; i < universities.size(); ++i )
    {
        for( UShort j = 0; j < answer.size(); ++j )
        {
            if( universities[ i ] > universities[ answer[ j ] ] )
            {
                // если рассматриваемый университет более широко представлен, чем какой-то из нашего ответа,
                // то нужно "сдвинуть вправо" весь массив ответов, начиная с текущей позиции в ответе;
                // а на текущую позицию в ответе - записать рассматриваемый университет
                for( UShort k = answer.size() - 1; k > j; --k )
                    answer[ k ] = answer[ k - 1 ];
                answer[ j ] = i;

                break;
            }
            else
            {
                // если рассматриваемый университет менее широко представлен, чем какой-то из нашего ответа, то ничего не делаем,
                // т.к. нам нужны университеты с наибольшим числом учащихся

                // если рассматриваемый университет так же широко представлен, как какой-то из нашего ответа, то ничего не делаем,
                // т.к. нас интересуют университеты с наименьшими id, а они попадают в ответ раньше

                continue;
            }
        }
    }

    for( UShort elem : answer )
        cout << elem << " ";

    return 0;
}
