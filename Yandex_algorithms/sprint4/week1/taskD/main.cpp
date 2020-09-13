#include "solution_tree.h"

#include <iostream>

using namespace std;

bool Solution( const Node* root );

bool test1() {
    Node* n1 = new Node( 4, nullptr, nullptr );
    Node* n2 = new Node( 3, nullptr, nullptr );
    Node* n3 = new Node( 3, nullptr, nullptr );
    Node* n4 = new Node( 4, nullptr, nullptr );

    Node* n5 = new Node( 2, n1, n2 );
    Node* n6 = new Node( 2, n3, n4 );

    Node* root = new Node( 4, n5, n6 );

    return Solution( root ) == true;
}

bool test2() {
    Node* n1 = new Node( 3, nullptr, nullptr );
    Node* n2 = new Node( 4, nullptr, nullptr );
    Node* n3 = new Node( 3, nullptr, nullptr );
    Node* n4 = new Node( 4, nullptr, nullptr );

    Node* n5 = new Node( 2, n1, n2 );
    Node* n6 = new Node( 2, n3, n4 );

    Node* root = new Node( 4, n5, n6 );

    return Solution( root ) == false;
}

bool test3() {
    Node* n1 = new Node( 5, nullptr, nullptr );
    Node* n2 = new Node( 6, nullptr, nullptr );
    Node* n3 = new Node( 7, nullptr, nullptr );
    Node* n4 = new Node( 7, nullptr, nullptr );
    Node* n5 = new Node( 6, nullptr, nullptr );
    Node* n6 = new Node( 5, nullptr, nullptr );

    Node* n7 = new Node( 4, n1, nullptr );
    Node* n8 = new Node( 3, n2, n3 );
    Node* n9 = new Node( 3, n4, nullptr );
    Node* n10 = new Node( 4, n5, n6 );

    Node* n11 = new Node( 2, n7, n8 );
    Node* n12 = new Node( 2, n9, n10 );

    Node* root = new Node( 1, n11, n12 );

    return Solution( root ) == false;
}

int main() {
    test1() ? cout << '+' : cout << '-'; cout << endl;
    test2() ? cout << '+' : cout << '-'; cout << endl;
    test3() ? cout << '+' : cout << '-'; cout << endl;

    return 0;
}
