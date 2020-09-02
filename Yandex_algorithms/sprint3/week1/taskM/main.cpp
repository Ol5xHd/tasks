#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;

bool IsSubsequence( const string &word, const string &encrypted )
{
    bool is_subseq = true;
    UShort word_ind = 0;
    UShort encrypted_ind = 0;
    while( word_ind < word.length() )
    {
        while( encrypted_ind < encrypted.length() )
        {
            if( word[ word_ind ] == encrypted[ encrypted_ind ] )
            {
                ++word_ind;
                ++encrypted_ind;
                break;
            }
            else
            {
                ++encrypted_ind;
            }
        }
        if( encrypted_ind >= encrypted.length() && word_ind < word.length() )
        {
            is_subseq = false;
            break;
        }
    }
    return is_subseq;
}

string Decrypt( const string &encrypted, vector<string> &words )
{
    sort( words.begin(), words.end() );
    string answer = "";
    for( const string &word : words )
    {
        if( IsSubsequence( word, encrypted ) )
        {
            if( word.length() > answer.length() )
                answer = word;
        }
    }
    return answer;
}

int main()
{
    string encrypted;
    getline( cin, encrypted );

    string line;
    getline( cin, line );
    UShort N = static_cast<UShort>( stoi( line ) );

    vector<string> words( N );
    for( UShort i = 0; i < N; ++i )
        getline( cin, words[ i ] );

    string answer = Decrypt( encrypted, words );
    cout << answer;

    return 0;
}
