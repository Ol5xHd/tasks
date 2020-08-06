#include "solution.h"

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