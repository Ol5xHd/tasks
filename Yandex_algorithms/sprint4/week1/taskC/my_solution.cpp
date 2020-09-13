#include "solution_tree.h"

#include <vector>

std::vector<std::vector<int>> Solution( const Node* root ) {
    std::vector<std::vector<int>> result;

    std::vector<const Node*> curr_lvl;
    curr_lvl.push_back( root );
    while( !( curr_lvl.empty() ) ) {
        std::vector<int> to_add;
        std::vector<const Node*> next_lvl;
        for( auto it = curr_lvl.begin(); it != curr_lvl.end(); ++it ) {
            to_add.push_back( ( *it )->value );
            const Node* left = ( *it )->left;
            if( left )
                next_lvl.push_back( left );
            const Node* right = ( *it )->right;
            if( right )
                next_lvl.push_back( right );
        }
        result.push_back( to_add );
        curr_lvl.swap( next_lvl );
    }

    return result;
}
