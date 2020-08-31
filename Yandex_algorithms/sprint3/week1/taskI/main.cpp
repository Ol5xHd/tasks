#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned short UShort;

void Counting( vector<UShort> &items )
{
    UShort pink = 0;
    UShort yellow = 0;
    UShort crimson = 0;
    for( UShort it : items )
    {
        switch( it )
        {
            case 0: ++pink; break;
            case 1: ++yellow; break;
            case 2: ++crimson; break;
        }
    }

    for( UShort i = 0; i < pink; ++i )
        cout << "0 ";
    for( UShort i = 0; i < yellow; ++i )
        cout << "1 ";
    for( UShort i = 0; i < crimson; ++i )
        cout << "2 ";
}

void InPlace( vector<UShort> &items )
{
    for( UShort i = 1; i < items.size(); ++i )
    {
        for( UShort j = i; j > 0 && items[ j ] < items[ j - 1 ]; --j )
        {
            UShort tmp = items[ j ];
            items[ j ] = items[ j - 1 ];
            items[ j - 1 ] = tmp;
        }
    }

    for( const UShort &it : items )
        cout << it << ' ';
}

int main()
{
    string line;

    getline( cin, line );
    UShort count = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    stringstream in_sstream( line );
    vector<UShort> items( count );
    for( UShort i = 0; i < count; ++i )
        in_sstream >> items[ i ];

    // Counting( items );
    InPlace( items );

    return 0;
}
