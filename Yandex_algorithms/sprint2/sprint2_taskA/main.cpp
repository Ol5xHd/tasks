#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;

struct Time
{
    Time() : mHours( 0 ), mMinutes( 0 ) {}
    Time( UShort hours ) : mHours( hours ), mMinutes( 0 ) {}
    Time( UShort hours, UShort minutes ) : mHours( hours ), mMinutes( minutes ) {}
    Time( const Time& time ) : mHours( time.mHours ), mMinutes( time.mMinutes ) {}
    Time( const string &time_str )
    {
        auto dot_pos = time_str.find( '.' );
        if( dot_pos == time_str.npos )
        {
            mHours = static_cast<UShort>( stoi( time_str ) );
            mMinutes = 0;
        }
        else
        {
            mHours = static_cast<UShort>( stoi( time_str.substr( 0, dot_pos ) ) );
            mMinutes = static_cast<UShort>( stoi( time_str.substr( dot_pos + 1 ) ) );
        }
    }

    const Time& operator=( const Time& time )
    {
        mHours = time.mHours;
        mMinutes = time.mMinutes;
    }

    friend bool operator<( const Time &left, const Time &right );
    friend bool operator>( const Time &left, const Time &right );
    friend bool operator==( const Time &left, const Time &right );
    friend bool operator!=( const Time &left, const Time &right );
    friend bool operator<=( const Time &left, const Time &right );
    friend bool operator>=( const Time &left, const Time &right );

    friend ostream &operator<<( ostream &os, const Time &time );

    UShort mHours;
    UShort mMinutes;
};

bool operator<( const Time &left, const Time& right )
{
    if( left.mHours < right.mHours )
        return true;
    else if( left.mHours > right.mHours )
        return false;
    else
    {
        if( left.mMinutes < right.mMinutes )
            return true;
        else
            return false;
    }
}

bool operator>( const Time &left, const Time &right )
{
    if( left.mHours > right.mHours )
        return true;
    else if( left.mHours < right.mHours )
        return false;
    else
    {
        if( left.mMinutes > right.mMinutes )
            return true;
        else
            return false;
    }
}

bool operator==( const Time &left, const Time &right )
{
    return left.mHours == right.mHours && left.mMinutes == right.mMinutes;
}

bool operator!=( const Time &left, const Time &right )
{
    return left.mHours != right.mHours || left.mMinutes != right.mMinutes;
}

bool operator<=( const Time &left, const Time &right )
{
    return operator<( left, right ) || operator==( left, right );
}

bool operator>=( const Time &left, const Time &right )
{
    return operator>( left, right ) || operator==( left, right );
}

ostream &operator<<( ostream &os, const Time &time )
{
    os << time.mHours;
    if( time.mMinutes > 0 )
        os << '.' << time.mMinutes;

    return os;
}

struct Lesson
{
    Lesson() : mBegin( 0, 0 ), mEnd( 0, 0 ) {}
    Lesson( const Time &begin, const Time &end ) : mBegin( begin ), mEnd( end ) {}
    Lesson( const string &begin_str, const string &end_str ) : mBegin( begin_str ), mEnd( end_str ) {}

    friend ostream &operator<<( ostream &os, const Lesson &lesson );

    Time mBegin;
    Time mEnd;
};

ostream &operator<<( ostream &os, const Lesson &lesson )
{
    os << lesson.mBegin << ' ' << lesson.mEnd;
    return os;
}

int main()
{
    string line;

    getline( cin, line );
    UShort lessons_count = static_cast<UShort>( stoi( line ) );

    vector<Lesson> lessons( lessons_count );
    for( UShort i = 0; i < lessons_count; ++i )
    {
        getline( cin, line );
        stringstream sstream( line );
        string begin_str, end_str;
        sstream >> begin_str >> end_str;
        lessons[ i ] = Lesson( begin_str, end_str );
    }

    sort( lessons.begin(), lessons.end(), []( const Lesson &left, const Lesson &right ) {
        if( left.mEnd > right.mEnd )
        {
            return true;
        }
        else if( left.mEnd == right.mEnd )
        {
            if( left.mBegin > right.mBegin )
                return true;
            else if( left.mBegin <= right.mBegin )
                return false;
        }
        else
        {
            return false;
        }
    } );

    stringstream output;
    UShort lessons_at_all = 0;
    while( lessons.size() > 0 )
    {
        Time last_time( lessons.rbegin()->mEnd );
        output << *( lessons.rbegin() ) << endl;
        lessons.pop_back();
        ++lessons_at_all;

        while( lessons.size() > 0 )
            if( lessons.rbegin()->mBegin < last_time )
                lessons.pop_back();
            else
                break;
    }

    cout << lessons_at_all << endl;
    cout << output.str();

    return 0;
}
