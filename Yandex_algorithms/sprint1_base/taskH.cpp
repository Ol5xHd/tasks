/*
struct Node {  
    Node(const std::string &value, Node* next, Node* prev) : value(value), next(next), prev(prev) {}  
 
    std::string value;  
    Node* next;  
    Node* prev;  
};  
*/

#include "solution.h"

Node* solution( Node* head )
{
	while( head->next )
	{
		Node* tmp = head->prev;
		head->prev = head->next;
		head->next = tmp;
		head = head->prev;
	}
	head->next = head->prev;
	
	return head;
}