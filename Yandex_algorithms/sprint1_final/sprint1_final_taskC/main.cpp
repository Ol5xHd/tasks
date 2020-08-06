/* Махов Александр, Алгоритмы, Когорта 03
 * задача C. Стековая Очередь
 * ID успешной посылки - 33744707
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * @brief структура элемента связного списка
 */
struct Node
{
    Node( int value ) : mValue( value ), mNext( nullptr ) {}
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
    void Put( int value )
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

            --mSize;
        }

        return res;
    }

    Node* mTop; // указатель на верхний элемент стэка
    size_t mSize; // размер стэка
};

/**
 * @brief структура очереди, реализованной через два стэка
 */
struct Queue
{
    Queue() : mSize( 0 ) {}

    /**
     * @brief поместить элемент в очередь
     * @param value - значение элемента
     */
    void Put( int value )
    {
        mStraight.Put( value );
        ++mSize;
    }

    /**
     * @brief определить, пуста ли очередь
     * @return true / false
     */
    bool Empty()
    {
        return mSize == 0 ? true : false;
    }

    /**
     * @brief служебный метод для переноса элементов из "прямого" стэка в "обратный"
     */
    void MoveStraightToReverse()
    {
        while( !( mStraight.Empty() ) )
        {
            int value = mStraight.Pop();
            mReverse.Put( value );
        }
    }

    /**
     * @brief изъять элемент из очереди, очередь должна быть не пустая
     * @return значение элемента
     */
    int Get()
    {
        int result = -1;

        if( Empty() )
        {
            // не должны сюда попадать
            cout << "Queue is empty!" << endl;
        }
        else
        {
            // по мере необходимости перекладываем элементы из "прямого" стэка в обратный
            if( mReverse.Empty() )
                MoveStraightToReverse();

            result = mReverse.Pop();
            --mSize;
        }

        return result;
    }

    /**
     * @brief получить размер очереди
     * @return размер очереди
     */
    size_t GetSize()
    {
        return mSize;
    }

    /* для добавления элементов в очередь будем использовать стэк mStraight,
     * а для изъятия элементов - стэк mReverse;
     * если пришла команда на изъятие элемента, переложим все элементы из mStraight в mReverse в обратном порядке;
     * такой трюк обеспечит соблюдение принципа FIFO
     */
    Stack mStraight; // "прямой" стэк; хранит элементы в порядке добавления
    Stack mReverse; // "обратный" стэк; хранит элементы в обратном порядке
    size_t mSize; // размер очереди
};

int main()
{
    string line;

    getline( cin, line );
    size_t N = static_cast<size_t>( stoi( line ) ); // количество команд

    string cmd;
    Queue que;
    stringstream output; // аккумулируем вывод программы в буфере для экономии времени
    for( size_t i = 0; i < N; ++i )
    {
        getline( cin, line );
        stringstream in_sstream( line );
        in_sstream >> cmd;
        if( cmd == "put" )
        {
            int value;
            in_sstream >> value;
            que.Put( value );
        }
        else if( cmd == "get" )
        {
            if( que.Empty() )
                output << "error" << endl;
            else
                output << que.Get() << endl;
        }
        else if( cmd == "get_size" )
        {
            output << que.GetSize() << endl;
        }
    }

    cout << output.str();

    return 0;
}
