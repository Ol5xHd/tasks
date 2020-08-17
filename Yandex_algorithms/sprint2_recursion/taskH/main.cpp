#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef unsigned short UShort;

void Generate( UShort N, UShort open_count, UShort close_count, string current_sequence, vector<string> &sequences )
{
    if( open_count + close_count == 2 * N )
    {
        sequences.push_back( current_sequence );
        return;
    }

    if( open_count < N )
        Generate( N, open_count + 1, close_count, current_sequence + "(", sequences );

    if( open_count > close_count )
        Generate( N, open_count, close_count + 1, current_sequence + ")", sequences );
}

int main()
{
    ifstream fin;
    fin.open( "input.txt" );
    UShort N = 0;
    fin >> N;

    vector<string> sequences;
    UShort open_count = 0;
    UShort close_count = 0;
    string current_sequence = "";
    Generate( N, open_count, close_count, current_sequence, sequences );

    for( auto sqn : sequences )
        cout << sqn << endl;

    return 0;
}
