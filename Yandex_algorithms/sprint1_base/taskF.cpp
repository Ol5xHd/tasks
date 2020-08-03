#include "solution.h"

Node* solution( Node* head, int idx )
{
	if( idx == 0 )
	{
		Node* new_head =  head->next;
		delete head;
		return new_head;
	}
	
	Node* prev = head;
	while( idx > 1 )
	{
		prev = prev->next;
		--idx;
	}
	
	Node* deleting = prev->next;
	prev->next = deleting->next;
	delete deleting;
	
	return head;
}