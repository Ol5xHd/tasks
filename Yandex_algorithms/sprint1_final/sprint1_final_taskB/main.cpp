#include <iostream>
#include <memory>

using namespace std;

struct Node
{
    Node() {}
    Node( shared_ptr<Node> _next ) : next( _next ) {}

    weak_ptr<Node> next;
};

bool HasCycle( std::shared_ptr<Node> head )
{
    bool has_cycle = false;

    std::shared_ptr<Node> curr = head; // текущий расматриваемый узел
    while( !( curr->next.expired() ) ) // проверяем узлы по порядку, пока они сущестуют
    {
        curr = curr->next.lock();
        if( curr->next.expired() )
        {
            // если за текущим узлом нет следующего, то добрались до конца списка; циклов нет
            break;
        }
        else
        {
            // если следующий узел есть, надо проверить, не встречался ли он раньше
            std::shared_ptr<Node> next = curr->next.lock(); // узел, следующий за рассматриваемым
            std::shared_ptr<Node> it = head; // узел-итератор, проходит все узлы от головы до текущего рассматриваемого
            while( it != curr )
            {
                if( it == next )
                {
                    // узел одновременно и до рассматриваемого, и после; обнаружили цикл
                    has_cycle = true;
                    break;
                }
                else
                {
                    it = it->next.lock();
                }
            }

            if( has_cycle )
                break;
        }
    }

    return has_cycle;
}

int main()
{
    std::shared_ptr<Node> n3( new Node() );
    std::shared_ptr<Node> n2( new Node( n3 ) );
    std::shared_ptr<Node> n1( new Node( n2 ) );
    n3->next = n1;

    std::shared_ptr<Node> n32( new Node() );
    std::shared_ptr<Node> n22( new Node( n32 ) );
    std::shared_ptr<Node> n12( new Node( n22 ) );

    std::shared_ptr<Node> n33( new Node() );
    std::shared_ptr<Node> n23( new Node( n33 ) );
    std::shared_ptr<Node> n13( new Node( n23 ) );
    n33->next = n23;

    if( HasCycle( n1 ) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    if( HasCycle( n12 ) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    if( HasCycle( n13 ) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
