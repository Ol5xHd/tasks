#include <iostream>
#include <vector>
#include <utility>
#include <memory>

using namespace std;

typedef unsigned short UShort;

struct my_struct {
    vector<pair<UShort, UShort>> v;
    UShort another;

    my_struct( UShort i ) : another( i ) {}

    void PushBack( UShort f, UShort s ) {
        v.push_back( make_pair( f, s ) );
    }
};

int main()
{
    shared_ptr<my_struct> mstr( new my_struct( 5 ) );

    // vector<pair<UShort, UShort>> v;
    for( UShort i = 0; i < 10; ++i )
        for( UShort j = 0; j < 10; ++j )
            mstr->PushBack( i, j );

    for( auto it : mstr->v )
        cout << it.first << ' ' << it.second << endl;

    return 0;
}
