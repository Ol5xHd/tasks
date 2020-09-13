#include "solution_tree.h"

#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int>> Solution( const Node* root );

bool test1() {
    Node* n1 = new Node( 32, nullptr, nullptr );
    Node* n2 = new Node( 17, nullptr, nullptr );
    Node* n3 = new Node( 21, nullptr, nullptr );

    Node* n4 = new Node( 28, n1, n2 );
    Node* n5 = new Node( 54, n3, nullptr );

    Node* root = new Node( 36, n4, n5 );

    if( Solution( root ) == std::vector<std::vector<int>>{ {36}, {28, 54}, {32, 17, 21} } )
        return true;
    else
        return false;
}

int main() {
    test1() ? cout << '+' : cout << '-'; cout << endl;

    return 0;
}
