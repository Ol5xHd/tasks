#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    getline( cin, line );
    size_t last_space = line.find_last_of( ' ' );
    cout << line.size() - last_space - 1;

    return 0;
}
