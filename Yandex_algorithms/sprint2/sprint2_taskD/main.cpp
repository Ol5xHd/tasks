#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned short UShort;

struct Item
{
    Item( UShort number, UShort cost, UShort weight ) : mNumber( number ), mCost( cost ), mWeight( weight ) {}

    friend ostream& operator<<( ostream &os, const Item& item );

    UShort mNumber;
    UShort mCost;
    UShort mWeight;
};

ostream& operator<<( ostream &os, const Item& item )
{
    cout << "Number = " << item.mNumber << ", Cost = " << item.mCost << ", Weight = " << item.mWeight;
}

int main()
{
    UShort max_weight = 0;
    cin >> max_weight;

    UShort N = 0;
    cin >> N;

    vector<Item> items;
    for( UShort i = 0; i < N; ++i )
    {
        UShort cost;
        cin >> cost;
        UShort weight;
        cin >> weight;
        items.push_back( Item( i, cost, weight ) );
    }

    sort( items.begin(), items.end(), []( const Item &left, const Item &right ) {
        if( right.mCost > left.mCost )
            return true;
        else if( right.mCost < left.mCost )
            return false;
        else
        {
            if( right.mWeight < left.mWeight )
                return true;
            else if( right.mWeight > left.mWeight )
                return false;
            else
            {
                if( right.mNumber < left.mNumber )
                    return true;
                else
                    return false;
            }
        }
    } );

    UShort curr_weight = 0;
    vector<UShort> chosen;
    while( items.size() > 0 )
    {
        if( items.back().mWeight > max_weight - curr_weight )
        {
            items.pop_back();
        }
        else
        {
            curr_weight += items.back().mWeight;
            chosen.push_back( items.back().mNumber );
            items.pop_back();
        }
    }
    sort( chosen.begin(), chosen.end() );

    for( UShort num : chosen )
        cout << num << ' ';

    return 0;
}
