#include "solution.h"

int solution( Node* head, const std::string &elem )
{
	int idx = 0;
	bool found = false;
	while( head->value != elem && head->next )
	{
		head = head->next;
		++idx;
	}
	
	if( head->value == elem )
		return idx;
	else
		return -1;
}