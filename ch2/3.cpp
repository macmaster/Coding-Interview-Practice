/* Cracking the Coding Interview
 * Chapter: 1
 * Problem: 3
 * "Implement an algorithm to delete a node in the middle of a single linked list, given 
	only access to that node
	EXAMPLE
	Input: the node ‘c’ from the linked list a->b->c->d->e
	Result: nothing is returned, but the new linked list looks like a->b->d->e"
 * Author : Ronny Macmaster
 * Date : 12/17/15                                       */

#include <iostream>
#include <stdexcept>

using namespace std;

struct linked_list{
	int data;
	struct linked_list *next;
};

/* Fails if tried on end node. */
/* 1. Copy Next Node into Current Node.
 * 2. Delete Next Node */
void remove_node(struct linked_list *node){
	struct linked_list *temp = node->next;
	node->data = node->next->data;
	node->next = node->next->next;
	delete temp;
}

void print(struct linked_list *head){
	while(head != NULL){
		cout << head->data << ", ";
		head = head->next;
	}
	cout << endl;
}
int main(){
	int data[10] ={0,1,2,3,4,5,6,7,8,9};
	struct linked_list *current, *prev, *head;
	
	current = head = new struct linked_list;
	for(int i = 0; i < 10; i++){
		current->data = data[i];
		current->next = new struct linked_list;
		prev = current;
		current = current->next;
	}
	delete prev->next; prev->next = NULL;
		
	
	cout << "Before Removal: ";
	print(head);
	
	cout << "After Removal: ";
	/*find node*/
	current = head;
	for(int i = 0; i < 4; i++){
		current = current->next;
	}
	remove_node(current);
	print(head);
	
	current = head;
	for(int i = 0; i < 10; i++){
		prev = current;
		current = current->next;
		delete prev;
	}
	
}
