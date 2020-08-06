#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

/**
 * @brief структура элемента связного списка
 */
struct Node
{
    Node( int value ) : mValue( value ) {}
    Node( int value, Node* next ) : mValue( value ), mNext( next ) {}

    int mValue; // значение элемента
    Node* mNext; // указатель на следующий элемент
};

/**
 * @brief структура стэка
 */
struct Stack
{
    Stack() : mTop( nullptr ), mSize( 0 ) {}

    /**
     * @brief определить, пустой ли стэк
     * @return true / false
     */
    bool Empty()
    {
        return mSize == 0 ? true : false;
    }

    /**
     * @brief положить в стэк новый элемент
     * @param value - значение элемента
     */
    void Push( int value )
    {
        if( Empty() )
        {
            mTop = new Node( value );
        }
        else
        {
            Node* new_node = new Node( value, mTop );
            mTop = new_node;
        }
        ++mSize;
    }

    /**
     * @brief извлечь верхний элемент из стэка
     * @return значение элемента
     */
    int Pop()
    {
        int res = -1;

        if( Empty() )
        {
            // не должно быть в тестах
            cout << "Stack is empty!" << endl;
        }
        else
        {
            res = mTop->mValue;

            Node* to_delete = mTop;
            mTop = mTop->mNext;
            delete to_delete;
        }

        return res;
    }

    /**
     * @brief извлечь два верхних элемента из стэка
     * @param first - первый извлекаемый элемент (верхний)
     * @param second - второй извлекаемый элемент (следующий за верхним)
     */
    void PopTwice( int &first, int& second )
    {
        first = Pop();
        second = Pop();
    }

    Node* mTop; // указатель на верхний элемент стэка
    size_t mSize; // размер стэка
};

const set<string> OPERATIONS{ "+", "-", "*", "/" };

/**
 * @brief обработать следующий входной элемент (операнд или операцию)
 * @param stack - стэк
 * @param elem - элемент входной последовательности
 */
void ProcessInputElem( Stack &stack, const string &elem )
{
    if( OPERATIONS.find( elem ) != OPERATIONS.end() )
    {
        // это операция
        int left, right;
        stack.PopTwice( right, left );
        if( elem == "+" )
            stack.Push( left + right );
        else if( elem == "-" )
            stack.Push( left - right );
        else if( elem == "*" )
            stack.Push( left * right );
        else if( elem == "/" )
            stack.Push( left / right );
    }
    else
    {
        // это операнд
        stack.Push( stoi( elem ) );
    }
}

int main()
{
    string input;
    getline( cin, input );
    stringstream in_sstream( input );
    Stack stack;
    for( string elem; in_sstream >> elem; )
        ProcessInputElem( stack, elem );

    cout << stack.Pop() << endl;

    return 0;
}
