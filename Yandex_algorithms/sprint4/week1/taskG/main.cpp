#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std; 

typedef unsigned short UShort;

struct Heap {

    void Insert( UShort first, UShort second ) {
        size_t child_ind = mArr.size();
        mArr.push_back( make_pair( first, second ) );

        if( child_ind > 0 ) {
            while( Less( mArr[ child_ind ], mArr[ ( child_ind - 1 ) / 2 ]  ) ) {
                Swap( child_ind, ( child_ind - 1 ) / 2 );
                child_ind = ( child_ind - 1 ) / 2;
            }
        }
    }

    pair<UShort, UShort> Peek() {
        pair<UShort, UShort> result = mArr[ 0 ];
        mArr[ 0 ] = mArr.back();
        mArr.pop_back();

        Heapify( 0 );

        return result;
    }

private:

    void Heapify( size_t root_ind ) {
        if( mArr.size() == 0 )
            return;

        size_t left_ind = 2 * root_ind + 1;
        size_t right_ind = 2 * root_ind + 2;
        if( left_ind > mArr.size() - 1 ) {
            return;
        }
        else if( right_ind > mArr.size() - 1 ) {
            if( Less( mArr[ left_ind ], mArr[ root_ind ] ) ) {
                Swap( left_ind, root_ind );
                Heapify( left_ind );
            }
        }
        else {
            if( Less( mArr[ root_ind ], mArr[ left_ind ] ) && Less( mArr[ root_ind ], mArr[ right_ind ] ) ) {
                return;
            }
            else {
                if( Less( mArr[ left_ind ], mArr[ right_ind ] ) ) {
                    Swap( left_ind, root_ind );
                    Heapify( left_ind );
                }
                else {
                    Swap( right_ind, root_ind );
                    Heapify( right_ind );
                }
            }
        }
    }

    void Swap( size_t ind1, size_t ind2 ) {
        pair<UShort, UShort> tmp = mArr[ ind1 ];
        mArr[ ind1 ] = mArr[ ind2 ];
        mArr[ ind2 ] = tmp;
    }

    bool Less( const pair<UShort, UShort> &left, const pair<UShort, UShort> &right ) const {
        UShort left_sum = left.first + left.second;
        UShort right_sum = right.first + right.second;
        if( left_sum < right_sum ) {
            return true;
        }
        else if( left_sum > right_sum ) {
            return false;
        }
        else {
            if( left.first < right.first )
                return true;
            else
                return false;
        }
    }

    vector<pair<UShort, UShort>> mArr;
};

int main() {
    string line;

    getline( cin, line );
    size_t n1 = static_cast<size_t>( stoi( line ) );

    getline( cin, line );
    vector<UShort> first( n1 );
    stringstream in_sstream( line );
    for( size_t i = 0; i < n1; ++i )
        in_sstream >> first[ i ];

    getline( cin, line );
    size_t n2 = static_cast<size_t>( stoi( line ) );

    getline( cin, line );
    vector<UShort> second( n2 );
    in_sstream.clear();
    in_sstream.str( line );
    for( size_t i = 0; i < n2; ++i )
        in_sstream >> second[ i ];

    getline( cin, line );
    size_t k = static_cast<size_t>( stoi( line ) );

    Heap heap;
    for( UShort it1 : first )
        for( UShort it2 : second )
            heap.Insert( it1, it2 );

    vector<pair<UShort, UShort>> answer;
    for( size_t i = 0; i < k; ++i ) {
        auto curr_pair = heap.Peek();
        answer.push_back( make_pair( min( curr_pair.first, curr_pair.second ), max( curr_pair.first, curr_pair.second ) ) );
    }

    sort( answer.begin(), answer.end(), []( const pair<UShort, UShort> left, const pair<UShort, UShort> right ) {
        if( left.first < right.first ) {
            return true;
        }
        else if( left.first > right.first ) {
            return false;
        }
        else {
            if( left.second < right.second )
                return true;
            else
                return false;
        }
    } );

    for( auto p : answer )
        cout << p.first << ' ' << p.second << endl;

    return 0;
}
