#include "solution_tree.h"

#include <iostream>

using namespace std;

void findMax( const Node* node, int &max );
int Solution( const Node* root );

bool test1() {
    Node* n1 = new Node( 14, nullptr, nullptr );
    Node* n2 = new Node( 15, nullptr, nullptr );
    Node* n3 = new Node( 3, nullptr, nullptr );
    Node* n4 = new Node( 0, nullptr, nullptr );
    Node* n5 = new Node( 1, nullptr, nullptr );

    Node* n6 = new Node( 8, n1, n2 );
    Node* n7 = new Node( 10, nullptr, n3 );
    Node* n8 = new Node( -2, nullptr, nullptr );
    Node* n9 = new Node( 6, n4, n5 );

    Node* n10 = new Node( 3, n6, n7 );
    Node* n11 = new Node( 5, n8, n9 );

    Node* root = new Node( 1, n10, n11 );

    bool result = false;
    if( Solution( root ) == 15 )
        result = true;

    return result;
}

bool test2() {
    Node* root = new Node( 1, nullptr, nullptr );

    bool result = false;
    if( Solution( root ) == 1 )
        result = true;

    return result;
}

bool test3() {
    Node* n1 = new Node( 14, nullptr, nullptr );
    Node* n2 = new Node( 15, nullptr, nullptr );
    Node* n3 = new Node( 3, nullptr, nullptr );
    Node* n4 = new Node( 0, nullptr, nullptr );
    Node* n5 = new Node( 1, nullptr, nullptr );

    Node* n6 = new Node( 8, n1, n2 );
    Node* n7 = new Node( 10, nullptr, n3 );
    Node* n8 = new Node( -2, nullptr, nullptr );
    Node* n9 = new Node( 6, n4, n5 );

    Node* n10 = new Node( 3, n6, n7 );
    Node* n11 = new Node( 5, n8, n9 );

    Node* root = new Node( 17, n10, n11 );

    bool result = false;
    if( Solution( root ) == 17 )
        result = true;

    return result;
}

bool test4() {
    Node* n1 = new Node( -14, nullptr, nullptr );
    Node* n2 = new Node( -15, nullptr, nullptr );
    Node* n3 = new Node( -3, nullptr, nullptr );
    Node* n4 = new Node( 0, nullptr, nullptr );
    Node* n5 = new Node( -1, nullptr, nullptr );

    Node* n6 = new Node( -8, n1, n2 );
    Node* n7 = new Node( -10, nullptr, n3 );
    Node* n8 = new Node( -2, nullptr, nullptr );
    Node* n9 = new Node( -6, n4, n5 );

    Node* n10 = new Node( -3, n6, n7 );
    Node* n11 = new Node( -5, n8, n9 );

    Node* root = new Node( -17, n10, n11 );

    bool result = false;
    if( Solution( root ) == 0 )
        result = true;

    return result;
}

int main()
{
    test1() ? cout << '+' : cout << '-'; cout << endl;
    test2() ? cout << '+' : cout << '-'; cout << endl;
    test3() ? cout << '+' : cout << '-'; cout << endl;
    test4() ? cout << '+' : cout << '-'; cout << endl;

    return 0;
}
