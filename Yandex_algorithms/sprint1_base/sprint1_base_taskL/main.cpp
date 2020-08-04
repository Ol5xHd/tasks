#include <iostream>
#include <string>

using namespace std;

struct Node
{
    Node( char value ) : mValue( value ) {}

    char mValue;
    Node* mNext;
};

struct Stack
{
    Stack() : mTop( nullptr ), mSize( 0 ) {}

    bool Push( char c )
    {
        bool result = true;

        if( mTop )
        {
            if( c == '(' or c == '[' or c == '{' )
            {
                Node* new_node = new Node( c );
                new_node->mNext = mTop;
                mTop = new_node;
                ++mSize;
            }
            else
            {
                if(
                    c== ')' && mTop->mValue == '('
                    || c== ']' && mTop->mValue == '['
                    || c== '}' && mTop->mValue == '{'
                )
                {
                    Node* new_top = mTop->mNext;
                    delete mTop;
                    mTop = new_top;
                    --mSize;
                }
                else
                {
                    result = false;
                }
            }
        }
        else
        {
            if( c == '(' or c == '[' or c == '{' )
            {
                mTop = new Node( c );
                ++mSize;
            }
            else
            {
                result = false;
            }
        }

        return result;
    }

    unsigned int Size()
    {
        return mSize;
    }

    Node* mTop;
    unsigned int mSize;
};

int main()
{
    string input;
    getline( cin, input );

    Stack stack;
    bool is_correct = true;
    for( char c : input )
    {
        if( is_correct )
        {
            is_correct = stack.Push( c );
        }
        else
        {
            break;
        }
    }

    if( is_correct && stack.Size() == 0 )
        cout << "True";
    else
        cout << "False";

    return 0;
}
