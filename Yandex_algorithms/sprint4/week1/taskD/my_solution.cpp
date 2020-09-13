#include "solution_tree.h"

#include <vector>

using namespace std;

bool Solution( const Node* root ) {
    auto HasLeft = []( const Node* node ) {
        if( node->left == nullptr )
            return false;
        else
            return true;
    };

    auto HasRight = []( const Node* node ) {
        if( node->right == nullptr )
            return false;
        else
            return true;
    };

    vector<const Node*> curr_lvl;
    curr_lvl.push_back( root );
    while( !( curr_lvl.empty() ) ) {
        for( size_t i = 0; i <= curr_lvl.size() / 2; ++i )
            if(
                curr_lvl[ i ]->value != curr_lvl[ curr_lvl.size() - 1 - i ]->value
                || HasLeft( curr_lvl[ i ] ) != HasRight( curr_lvl[ curr_lvl.size() - 1 - i ] )
                || HasRight( curr_lvl[ i ] ) != HasLeft( curr_lvl[ curr_lvl.size() - 1 - i ] )
            )
                return false;

        std::vector<const Node*> next_lvl;
        for( auto it = curr_lvl.begin(); it != curr_lvl.end(); ++it ) {
            const Node* left = ( *it )->left;
            if( left )
                next_lvl.push_back( left );
            const Node* right = ( *it )->right;
            if( right )
                next_lvl.push_back( right );
        }
        curr_lvl.swap( next_lvl );
    }

    return true;
}
