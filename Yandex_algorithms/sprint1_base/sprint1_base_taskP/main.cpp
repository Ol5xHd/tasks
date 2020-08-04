#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef unsigned short UShort;

struct Node
{
    Node( int value ) : mValue( value ), mNext( nullptr ), mPrev( nullptr ) {}

    int mValue;
    Node* mNext;
    Node* mPrev;
};

struct Queue
{
    Queue() : mHead( nullptr ), mTail( nullptr ), mSize( 0 ) {}

    void Get( stringstream &output )
    {
        if( !mHead )
        {
            output << "error" << endl;
        }
        else
        {
            output << mHead->mValue << endl;
            Node* deleting = mHead;
            mHead = mHead->mPrev;
            if( mHead )
                mHead->mNext = nullptr;
            else
                mTail = nullptr;
            delete deleting;
            --mSize;
        }
    }

    void Put( int value )
    {
        if( !mTail )
        {
            mHead = new Node( value );
            mTail = mHead;
        }
        else
        {
            Node* new_node = new Node( value );
            new_node->mNext = mTail;
            mTail->mPrev = new_node;
            mTail = new_node;
        }
        ++mSize;
    }

    void Size( stringstream &output )
    {
        output << mSize << endl;
    }

    Node* mHead;
    Node* mTail;
    UShort mSize;
};

int main()
{
    string line;

    getline( cin, line );
    UShort N = static_cast<UShort>( stoi( line ) );

    string cmd;
    stringstream output;
    Queue queue;
    for( UShort i = 0; i < N; ++i )
    {
        getline( cin, line );
        stringstream sstream( line );
        sstream >> cmd;
        if( cmd == "get" )
        {
            queue.Get( output );
        }
        else if( cmd == "put" )
        {
            int value;
            sstream >> value;
            queue.Put( value );
        }
        else if( cmd == "size" )
        {
            queue.Size( output );
        }
    }

    cout << output.str();

    return 0;
}
