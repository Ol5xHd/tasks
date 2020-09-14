#include "solution_tree.h"

#include <iostream>

using namespace std;

bool Solution( const Node* root );

bool test1() {
    Node* n1 = new Node( 2, nullptr, nullptr );
    Node* n2 = new Node( 0, nullptr, nullptr );
    Node* root = new Node( 1, n1, n2 );

    return Solution( root ) == true;
}

bool test2() {
    Node* n1 = new Node( 3, nullptr, nullptr );
    Node* n2 = new Node( 6, nullptr, nullptr );

    Node* n3 = new Node( 2, nullptr, nullptr );
    Node* n4 = new Node( 0, n1, n2 );

    Node* root = new Node( 1, n3, n4 );

    return Solution( root ) == true;
}

bool test3() {
    Node* n1 = new Node( 12, nullptr, nullptr );

    Node* n2 = new Node( 4, n1, nullptr );
    Node* n3 = new Node( 8, nullptr, nullptr );

    Node* n4 = new Node( 2, nullptr, nullptr );
    Node* n5 = new Node( 7, n2, n3 );

    Node* root = new Node( 0, n4, n5 );

    return Solution( root ) == false;
}

int main()
{
    test1() ? cout << '+' : cout << '-'; cout << endl;
    test2() ? cout << '+' : cout << '-'; cout << endl;
    test3() ? cout << '+' : cout << '-'; cout << endl;

    return 0;
}
