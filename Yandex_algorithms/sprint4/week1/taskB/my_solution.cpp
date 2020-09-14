#include "solution_tree.h"

#include <algorithm>

typedef unsigned short UShort;

bool SolutionImpl( const Node* root, UShort &height ) {
    if( !root ) {
        height = 0;
        return true;
    }

    UShort left_height = 0;
    UShort right_height = 0;
    bool left_balanced = SolutionImpl( root->left, left_height );
    bool right_balanced = SolutionImpl( root->right, right_height );
    height = std::max( left_height, right_height ) + 1;

    if( left_balanced && right_balanced ) {
        if( left_height == right_height || left_height + 1 == right_height || left_height == right_height + 1 )
            return true;
        else
            return false;
    }
    else {
        return false;
    }
}

bool Solution( const Node* root ) {
    UShort height = 0;
    return SolutionImpl( root, height );
}
