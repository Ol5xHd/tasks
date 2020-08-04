#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef unsigned short UShort;

struct MyQueue
{
    MyQueue( UShort length )
    {
        mArr = new int[ length ];
        mLength = length;
        mHead = 0;
        mTail = 0;
        mSize = 0;
    }

    void Push( int value )
    {
        mArr[ mTail ] = value;
        mTail = ( mTail + 1 ) % mLength;
        ++mSize;
    }

    void Pop( stringstream &output )
    {
        if( mSize == 0 )
        {
            output << "None" << endl;
        }
        else
        {
            output << mArr[ mHead ] << endl;
            mHead = ( mHead + 1 ) % mLength;
            --mSize;
        }
    }

    void Peek( stringstream &output )
    {
        if( mSize == 0 )
            output << "None" << endl;
        else
            output << mArr[ mHead ] << endl;
    }

    void Size( stringstream &output )
    {
        output << mSize << endl;
    }

    int* mArr;
    UShort mLength;
    UShort mHead;
    UShort mTail;
    UShort mSize;
};

int main()
{
    string line;

    // считываем количество команд
    getline( cin, line );
    UShort N = static_cast<UShort>( stoi( line ) );

    MyQueue my_queue( N ); // создаём нашу очередь
    stringstream output( "" ); // буффер, где будем собирать вывод программы, чтобы не тратить время
    string cmd;
    for( UShort i = 0; i < N; ++i ) // последовательно считываем команды
    {
        getline( cin, line );
        stringstream sstream( line );
        sstream >> cmd;
        if( cmd == "push" )
        {
            int value;
            sstream >> value;
            my_queue.Push( value );
        }
        else if( cmd == "pop" )
        {
            my_queue.Pop( output );
        }
        else if( cmd == "peek" )
        {
            my_queue.Peek( output );
        }
        else if( cmd == "size" )
        {
            my_queue.Size( output );
        }
    }

    cout << output.str();

    return 0;
}
