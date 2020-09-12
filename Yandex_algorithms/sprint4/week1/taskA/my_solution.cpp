#include "solution_tree.h"

// v2

void findMax( const Node* node, int &max ) {
    if( !node )
        return;
    if( node->value > max )
        max = node->value;
    findMax( node->left, max );
    findMax( node->right, max );
}

int Solution( const Node* root ) {
    int max = root->value;
    findMax( root, max );
    return max;
}
