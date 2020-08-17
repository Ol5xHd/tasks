#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char letters[]{
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z'
    };

    ifstream fin;
    fin.open( "input.txt" );
    char last_letter = 'a';
    fin >> last_letter;

    char* curr_letter = letters;
    while( *curr_letter != last_letter )
    {
        cout << *curr_letter << ' ';
        ++curr_letter;
    }
    cout << last_letter;

    return 0;
}
