#include "solution_tree.h"

#include <iostream>

using namespace std;

bool Solution( const Node* root1, const Node* root2 );

bool test1() {
    Node* n1_1 = new Node( 2, nullptr, nullptr );
    Node* n2_1 = new Node( 3, nullptr, nullptr );

    Node* root_1 = new Node( 1, n1_1, n2_1 );

    Node* n1_2 = new Node( 2, nullptr, nullptr );
    Node* n2_2 = new Node( 3, nullptr, nullptr );

    Node* root_2 = new Node( 1, n1_2, n2_2 );

    return Solution( root_1, root_2 ) == true;
}

bool test2() {
    Node* n1_1 = new Node( 3, nullptr, nullptr );
    Node* root_1 = new Node( 1, n1_1, nullptr );

    Node* n1_2 = new Node( 3, nullptr, nullptr );
    Node* root_2 = new Node( 1, nullptr, n1_2 );

    return Solution( root_1, root_2 ) == false;
}

int main()
{
    test1() ? cout << '+' : cout << '-'; cout << endl;
    test2() ? cout << '+' : cout << '-'; cout << endl;

    return 0;
}
