#include "solution_tree.h"

#include <iostream>
#include <vector>

using namespace std;

vector<int> Solution( const Node* root );

bool test1() {
    Node* n1 = new Node( 17, nullptr, nullptr );
    Node* n2 = new Node( 14, nullptr, nullptr );

    Node* n3 = new Node( 4, nullptr, nullptr );
    Node* n4 = new Node( 5, nullptr, nullptr );
    Node* n5 = new Node( 8, n1, nullptr );
    Node* n6 = new Node( 10, n2, nullptr );

    Node* n7 = new Node( 2, n3, n4 );
    Node* n8 = new Node( 3, n5, n6 );

    Node* root = new Node( 1, n7, n8 );

    return Solution( root ) == vector<int>{ 1, 2, 4, 17 };
}

int main()
{
    test1() ? cout << '+' : cout << '-'; cout << endl;

    return 0;
}
