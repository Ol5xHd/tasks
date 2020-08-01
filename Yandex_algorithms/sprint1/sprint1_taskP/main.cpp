#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// мапа соответствия между цифрой и буквами
const map<char, string> LETTERS {
    { '2', "abc" },
    { '3', "def" },
    { '4', "ghi" },
    { '5', "jkl" },
    { '6', "mno" },
    { '7', "pqrs" },
    { '8', "tuv" },
    { '9', "wxyz" }
};

/**
 * @brief рекурсивный метод построения всех возможных комбинаций слов
 * @param combinations - вектор, где хранятся все финальные комбинации (промежутночные не хранятся!)
 * @param digits - строка цифр, которые надо добавить к текущему слову
 * @param current - текущее слово, к которому будем присоединять все возможные варианты букв
 */
void AddNumber( vector<string> &combinations, const string &digits, string &current )
{
    if( digits.empty() )
    {
        // если цифр не осталось, то можно текущее слово записать в результат
        combinations.push_back( current );
    }
    else
    {
        // цифры ещё есть, будем по очереди их добавлять к текущему слову
        for( char c : LETTERS.at( digits[ 0 ] ) )
        {
            current.append( 1, c ); // добавили букву
            AddNumber( combinations, digits.substr( 1 ), current ); // посчитали для неё все возможные продолжения
            current.pop_back(); // удалили, чтобы можно было записать на её место следующую
        }
    }
}

int main()
{
    // читаем входную последжовательность цифр
    string digits;
    getline( cin, digits );

    vector<string> combinations; // результат, в нём будут все комбинации
    string current_temp_string; // временный объект, нужен для старта метода
    AddNumber( combinations, digits, current_temp_string );

    for( string &word : combinations )
        cout << word << ' ';

    return 0;
}
