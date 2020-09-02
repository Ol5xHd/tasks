#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;

void QuickSortImpl( vector<UShort*> &elems, UShort ind_beg, UShort ind_end )
{
    if( ind_beg == ind_end )
        return;

    UShort base = *( elems[ ind_beg ] );
    UShort less_eq_count = 0;
    UShort greater_count = 0;
    for( UShort i = ind_beg + 1; i <= ind_end; ++i )
        if( *( elems[ i ] ) <= base )
            ++less_eq_count;
        else
            ++greater_count;
    UShort ind_center = ind_beg + less_eq_count;

    {
        UShort tmp = *( elems[ ind_center ] );
        *( elems[ ind_center ] ) = *( elems[ ind_beg ] );
        *( elems[ ind_beg ] ) = tmp;
    }

    UShort ind_left = ind_beg;
    UShort ind_right = ind_center + 1;
    while( ind_left < ind_center && ind_right <= ind_end )
    {
        if( *( elems[ ind_left ] ) > base && *( elems[ ind_right ] ) <= base )
        {
            UShort tmp = *( elems[ ind_left ] );
            *( elems[ ind_left ] ) = *( elems[ ind_right ] );
            *( elems[ ind_right ] ) = tmp;
        }
        else if( *( elems[ ind_left ] ) > base )
        {
            ++ind_right;
        }
        else if( *( elems[ ind_right ] ) <= base )
        {
            ++ind_left;
        }
        else
        {
            ++ind_left;
            ++ind_right;
        }
    }

    if( ind_beg < ind_center )
        QuickSortImpl( elems, ind_beg, ind_center - 1 );
    if( ind_center < ind_end )
        QuickSortImpl( elems, ind_center + 1, ind_end );
}

void QuickSort( vector<UShort*> &elems )
{
    UShort ind_beg = 0;
    UShort ind_end = static_cast<UShort>( elems.size() ) - 1;
    QuickSortImpl( elems, ind_beg, ind_end );
}

void SortCurrDiagonal( UShort** matrix, UShort rows, UShort cols, UShort start_row, UShort start_col )
{
    vector<UShort*> elems;
    for( UShort i = start_row, j = start_col; i < rows && j < cols; ++i, ++j )
        elems.push_back( &( matrix[ i ][ j ] ) );
    QuickSort( elems );
}

void DiagSort( UShort** matrix, UShort rows, UShort cols )
{
    for( UShort i = 1; i < rows; ++i )
        SortCurrDiagonal( matrix, rows, cols, i, 0 );
    for( UShort j = 0; j < cols; ++j )
        SortCurrDiagonal( matrix, rows, cols, 0, j );
}

int main()
{
    string line;

    getline( cin, line );
    UShort rows = static_cast<UShort>( stoi( line ) );

    getline( cin, line );
    UShort cols = static_cast<UShort>( stoi( line ) );

    UShort** matrix = new UShort*[ rows ];
    for( UShort i = 0; i < rows; ++i )
    {
        getline( cin, line );
        stringstream in_sstream( line );
        matrix[ i ] = new UShort[ cols ];
        for( UShort j = 0; j < cols; ++j )
            in_sstream >> matrix[ i ][ j ];
    }

    DiagSort( matrix, rows, cols );

    for( UShort i = 0; i < rows; ++i )
    {
        for( UShort j = 0; j < cols; ++j )
            cout << matrix[ i ][ j ] << ' ';
        cout << endl;
    }

    return 0;
}
