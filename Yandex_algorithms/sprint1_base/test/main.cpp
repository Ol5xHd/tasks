#include <iostream>

using namespace std;

struct Node
{
    char* mValue;
    Node* mNext;

    Node( char* value ) : mValue( value ), mNext( nullptr ) {}
};

Node* CreateList()
{
    Node* head = new Node( "head" );
    head->mNext = new Node( "index1" );
    head->mNext->mNext = new Node( "index2" );
    head->mNext->mNext->mNext = new Node( "index3" );

    return head;
}

void PrintList( Node* head )
{
    while( head->mNext )
    {
        cout << head->mValue << endl;
        head = head->mNext;
    }
    cout << head->mValue << endl;
}

Node* solution( Node* head, int idx )
{
    if( idx == 0 )
    {
        Node* new_head =  head->mNext;
        delete head;
        return new_head;
    }

    Node* prev = head;
    while( idx > 1 )
    {
        prev = prev->mNext;
        --idx;
    }

    Node* deleting = prev->mNext;
    prev->mNext = deleting->mNext;
    delete deleting;

    return head;
}

int main()
{
    Node* head = CreateList();
    PrintList( head );
    cout << endl;
    head = solution( head, 1 );
    PrintList( head );

    return 0;
}
