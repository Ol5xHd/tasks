#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main()
{
    string line;
    getline( cin, line );
    short N;
    N = static_cast<short>( stoi( line ) );

    getline( cin, line );
    stringstream sstream( line );
    map<short, bool> ids;
    for( short id; sstream >> id; )
    {
        if( ids.find( id ) == ids.end() )
        {
            // ещё не встречали такого сотрудника
            ids[ id ] = true;
        }
        else
        {
            // уже встречали такого сотрудника
            if( ids[ id ] )
                ids[ id ] = false;
            else
                ids[ id ] = true;
        }
    }

    for( auto pair : ids )
        if( pair.second )
            cout << pair.first;

    return 0;
}
