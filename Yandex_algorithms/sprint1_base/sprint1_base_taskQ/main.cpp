#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef unsigned short UShort;

struct Deque
{
    Deque( UShort max_size )
    {
        mArr = new int[ max_size ];
        mHead = 0;
        mTail = 0;
        mMaxSize = max_size;
        mSize = 0;
    }

    void PushBack( int value, stringstream &output )
    {
        if( mSize < mMaxSize )
        {
            if( mSize != 0 )
                mTail = ( mTail + 1 ) % mMaxSize;
            mArr[ mTail ] = value;
            ++mSize;
        }
        else
        {
            output << "error" << endl;
        }
    }

    void PushFront( int value, stringstream &output )
    {
        if( mSize < mMaxSize )
        {
            if( mSize != 0 )
            {
                if( mHead == 0 )
                    mHead = mMaxSize - 1;
                else
                    mHead = mHead - 1;
            }
            mArr[ mHead ] = value;
            ++mSize;
        }
        else
        {
            output << "error" << endl;
        }
    }

    void PopFront( stringstream &output )
    {
        if( mSize == 0 )
        {
            output << "error" << endl;
        }
        else
        {
            output << mArr[ mHead ] << endl;
            if( mSize > 1 )
                mHead = ( mHead + 1 ) % mMaxSize;
            --mSize;
        }
    }

    void PopBack( stringstream &output )
    {
        if( mSize == 0 )
        {
            output << "error" << endl;
        }
        else
        {
            output << mArr[ mTail ] << endl;
            if( mSize > 1 )
            {
                if( mTail == 0 )
                    mTail = mMaxSize - 1;
                else
                    mTail = ( mTail - 1 ) % mMaxSize;
            }
            --mSize;
        }
    }

    int* mArr;
    UShort mHead;
    UShort mTail;
    UShort mMaxSize;
    UShort mSize;
};

int main()
{
    string line;

    getline( cin, line );
    UShort N = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    UShort MAX_SIZE = static_cast<UShort>( stoi( line ) );

    string cmd;
    Deque deq( MAX_SIZE );
    stringstream output;
    for( UShort i = 0; i < N; ++i )
    {
        getline( cin, line );
        stringstream sstream( line );
        sstream >> cmd;
        if( cmd == "push_back" )
        {
            int value;
            sstream >> value;
            deq.PushBack( value, output );
        }
        else if( cmd == "push_front" )
        {
            int value;
            sstream >> value;
            deq.PushFront( value, output );
        }
        else if( cmd == "pop_front" )
        {
            deq.PopFront( output );
        }
        else if( cmd == "pop_back" )
        {
            deq.PopBack( output );
        }
    }

    cout << output.str();

    return 0;
}
