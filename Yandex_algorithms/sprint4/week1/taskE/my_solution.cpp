#include "solution_tree.h"

bool Solution( const Node* root1, const Node* root2 ) {
    if( root1 && root2 ) {
        if( root1->value != root2->value ) {
            return false;
        }
        else {
            bool left = Solution( root1->left, root2->left );
            bool right = Solution( root1->right, root2->right );
            return left && right;
        }
    }
    else {
        if( !root1 && !root2 )
            return true;
        else
            return false;
    }
}
