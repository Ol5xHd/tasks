#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned short UShort;

int main()
{
    string line;
    getline( cin, line );
    UShort N = static_cast<UShort>( stoi( line ) );

    vector<string> cources;
    for( UShort i = 0; i < N; ++i )
    {
        getline( cin, line );
        bool can_add = true;
        for( string &curr_str : cources )
        {
            if( curr_str == line )
            {
                can_add = false;
                break;
            }
        }
        if( can_add )
            cources.push_back( line );
    }

    for( string &elem : cources )
        cout << elem << endl;

    return 0;
}
