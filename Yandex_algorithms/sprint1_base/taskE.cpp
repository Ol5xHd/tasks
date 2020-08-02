#include "solution.h"

void solution(Node* head)
{
	while( head->next )
    {
    	printf( "%s\n", head->value.c_str() );
    	head = head->next;
    }
    printf( "%s", head->value.c_str() );
}