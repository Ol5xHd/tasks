#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node
{
    int mValue;
    Node* mNext;
};

struct Stack
{
    Node* mTop;
    int mMax;
    stringstream mResult;

    void Push( int value )
    {
        if( !mTop )
        {
            mTop = new Node();
            mTop->mValue = value;
            mMax = value;
        }
        else
        {
            Node* new_node = new Node();
            new_node->mValue = value;
            new_node->mNext = mTop;
            mTop = new_node;
            if( value > mMax )
                mMax = value;
        }
    }

    void FindNewMax()
    {
        if( mTop )
        {
            Node* curr = mTop;
            mMax = curr->mValue;
            curr = curr->mNext;
            while( curr )
            {
                if( curr->mValue > mMax )
                    mMax = curr->mValue;
                curr = curr->mNext;
            }
        }
    }

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

            if( deleting->mValue == mMax )
                FindNewMax();

            delete deleting;
        }
    }

    void GetMax()
    {
        if( !mTop )
            // cout << "None" << endl;
            mResult << "None" << endl;
        else
            // cout << mMax << endl;
            mResult << mMax << endl;
    }
};

int main()
{
    string line;
    getline( cin, line );
    unsigned short N = static_cast<unsigned short>( stoi( line ) );

    Stack* stack = new Stack();
    stack->mTop = nullptr;
    for( unsigned short i = 0; i < N; ++i )
    {
        getline( cin, line );
        stringstream sstream( line );
        string cmd;
        sstream >> cmd;
        if( cmd == "push" )
        {
            int value;
            sstream >> value;
            stack->Push( value );
        }
        else if( cmd == "pop" )
        {
            stack->Pop();
        }
        else if( cmd == "get_max" )
        {
            stack->GetMax();
        }
    }

    cout << stack->mResult.str();

    return 0;
}
