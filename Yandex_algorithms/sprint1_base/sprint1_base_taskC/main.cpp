#include <iostream>
#include <string>
#include <set>

using namespace std;

typedef unsigned short UShort;

int main()
{
    string input;
    getline( cin, input );

    UShort best_len = 0;
    for( UShort beg_ind = 0; beg_ind < input.size(); ++beg_ind )
    {
        set<char> unique_chars;
        bool doubling_found = false;
        for( UShort curr_ind = beg_ind; curr_ind < input.size(); ++curr_ind )
        {
            if( unique_chars.find( input[ curr_ind ] ) == unique_chars.end() )
            {
                unique_chars.insert( input[ curr_ind ] );
            }
            else
            {
                UShort curr_len = curr_ind - beg_ind;
                if( curr_len > best_len )
                    best_len = curr_len;
                doubling_found = true;
                break;
            }
        }
        if( !doubling_found )
        {
            UShort curr_len = input.size() - beg_ind;
            if( curr_len > best_len )
                best_len = curr_len;
        }
    }

    cout << best_len;

    return 0;
}
