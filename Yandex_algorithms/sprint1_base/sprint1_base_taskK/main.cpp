#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

struct Node
{
    int mValue;
    Node* mNext;
};

struct Stack
{
    Node* mTop; // указатель на вершину стека
    stringstream mResult; // буффер для вывода команд
    unordered_set<int> mElems; // множество уникальных элементов стека
    unsigned int mSize;

    // поместить элемент в стек
    void Push( int value )
    {
        // храним только уникальные элементы в стеке
        if( mElems.find( value ) != mElems.end() )
            return;
        else
            mElems.insert( value );

        if( !mTop )
        {
            mTop = new Node();
            mTop->mValue = value;
            mSize = 1;
        }
        else
        {
            Node* new_node = new Node();
            new_node->mValue = value;
            new_node->mNext = mTop;
            mTop = new_node;
            ++mSize;
        }
    }

    // удалить верхний элемент стека
    void Pop()
    {
        if( !mTop )
        {
            // cout << "error" << endl;
            mResult << "error" << endl;
        }
        else
        {
            Node* deleting = mTop;
            mTop = mTop->mNext;
            mElems.erase( deleting->mValue );
            --mSize;

            delete deleting;
        }
    }

    // напечатать число с вершины стека
    void Peek()
    {
        if( !mTop )
            mResult << "error" << endl;
        else
            mResult << mTop->mValue << endl;
    }

    // напечатать размер стека
    void Size()
    {
        if( !mTop )
            mResult << "0" << endl;
        else
            mResult << mSize << endl;
    }
};

int main()
{
    string line;

    // считываем количество команд
    getline( cin, line );
    unsigned short N = static_cast<unsigned short>( stoi( line ) );

    // создаём объект стека
    Stack* stack = new Stack();
    stack->mTop = nullptr;
    // считываем собственно команды
    for( unsigned short i = 0; i < N; ++i )
    {
        getline( cin, line );
        stringstream sstream( line );
        string cmd;
        sstream >> cmd;
        if( cmd == "push" ) //
        {
            int value;
            sstream >> value;
            stack->Push( value );
        }
        else if( cmd == "pop" ) //
        {
            stack->Pop();
        }
        else if( cmd == "peek" )
        {
            stack->Peek();
        }
        else if( cmd == "size" )
        {
            stack->Size();
        }
    }

    cout << stack->mResult.str();

    return 0;
}
