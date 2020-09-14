#include "solution_tree.h"

#include <vector>

using namespace std;

vector<int> Solution( const Node* root ) {
    vector<int> result;

    vector<const Node*> curr_lvl;
    curr_lvl.push_back( root );
    while( !( curr_lvl.empty() ) ) {
        result.push_back( curr_lvl.front()->value );

        vector<const Node*> next_lvl;
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

    return result;
}
