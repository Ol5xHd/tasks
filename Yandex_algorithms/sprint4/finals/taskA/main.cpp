/**
 * Махов Александр, Алгоритмы, Когорта 03
 * спринт 4, задача A. Разные деревья поиска
 * ID успешной посылки - 34563286
 */

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

typedef unsigned short UShort;
typedef unsigned long ULong;

// рекурсивная реализация алгоритма для поиска количества деревьев
// elems - вектор с вершинами для построения дерева
// возвращает количество возможных деревьев
ULong SearchTreesCountImpl( const vector<UShort> &elems ) {
    // база рекурсии - из 1 и менее вершин можно построить только 1 дерево
    if( elems.size() < 2 ) {
        return 1;
    }

    // будем считать количество возможных деревьев, перебирая все вершины из доступных (представляя каждую корнем),
    // и для каждой будем считать количество возможных левых и правых поддеревьев;
    // тогда для одной вершины количество возможных деревьев будет равно произведению количества левых деревьев на количество правых,
    // а общее количество - сумма произведений по всем вершинам

    ULong count = 0;
    for( size_t i = 0; i < elems.size(); ++i ) {
        // строим множество вершин для левого дерева - они должны быть меньше корня
        auto less_beg = elems.begin();
        auto less_end = elems.begin();
        advance( less_end, i );
        vector<UShort> less( less_beg, less_end );

        // строим множество вершин для правого дерева - они должны быть больше корня
        auto greater_beg = elems.begin();
        advance( greater_beg, i + 1 );
        auto greater_end = elems.end();
        vector<UShort> greater( greater_beg, greater_end );

        count += ( SearchTreesCountImpl( less ) * SearchTreesCountImpl( greater ) );
    }

    return count;
}

// метод вычисления количества возможных деревьев, красивая обёртка для пользователя
// N - количество вершин дерева (от 1 до N включительно)
// возвращает количество возможных деревьев
ULong SearchTreesCount( UShort N ) {
    vector<UShort> elems( N );
    for( UShort i = 0; i < N; ++i )
        elems[ i ] = i + 1;

    return SearchTreesCountImpl( elems );
}

int main()
{
    UShort N = 0;
    cin >> N;

    cout << SearchTreesCount( N ) << endl;

    return 0;
}
