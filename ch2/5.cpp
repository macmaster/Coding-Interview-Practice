/* Cracking the Coding Interview
 * Chapter: 1
 * Problem: 5
 * "Given a circular linked list, implement an algorithm which returns node at the beginning of the loop
	DEFINITION
	Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an 
	earlier node, so as to make a loop in the linked list
	EXAMPLE
	input: A -> B -> C -> D -> E -> C [the same C as earlier]
	output: C"
 * Author : Ronny Macmaster
 * Date : 12/17/15                                       */

#include <iostream>
#include <stdexcept>
#include <map>

using namespace std;

struct linked_list{
	int data;
	struct linked_list *next;
};

void print(struct linked_list *head);
void empty(struct linked_list *head);

struct linked_list *find_head(struct linked_list *list){
	map<struct linked_list *, bool> m; //map of access flags
	while(list != NULL){
		try{
			m.at(list);
			return list;
		}
		catch(out_of_range &oor){
			m[list] = true;
			list = list->next;
		}
	}
	return NULL; // Not a Circular list!!
}

int main(){
	int data1[3] ={0,1,2};
	int data2[3] ={5,4,3};
	int data3[3] ={9,6,8};
	struct linked_list *current, *prev, *list1, *list2, *list3;
	
	// build 2nd sublist
	current = list2 = new struct linked_list;
	for(int i = 0; i < 3; i++){
		current->data = data2[i];
		current->next = new struct linked_list;
		prev = current;
		current = current->next;
	}
	delete prev->next; prev->next = NULL;
	
	// build 1st sublist
	current = list1 = new struct linked_list;
	for(int i = 0; i < 3; i++){
		current->data = data1[i];
		current->next = new struct linked_list;
		prev = current;
		current = current->next;
	}
	delete prev->next; prev->next = NULL;
	
	// chain 2nd sublist to 1st sublist
	// 0->1->2->5->4->3->NULL
	prev->next = list2;
		
	// build 3rd sublist
	current = list3 = new struct linked_list;
	for(int i = 0; i < 3; i++){
		current->data = data3[i];
		current->next = new struct linked_list;
		prev = current;
		current = current->next;
	}
	delete prev->next; prev->next = NULL;
	
	//chain 3rd sublist to 1st sublist
	// 9->6->8->0->1->2->5->4->3->NULL
	prev->next = list1;
	//chain end to middle to form a ring
	// 9->6->8->0->1->2->5->4->3  ->  0->1->2->5->4->3->0->...
	current = list3;
	while(current != NULL){
		prev = current;
		current = current->next;
	}
	prev->next = list1;
	
	// Print Results	
	cout << "Result : " << find_head(list3)->data << endl;
	// Empty All Numbers
	empty(list3);
	
}

void print(struct linked_list *head){
	while(head != NULL){
		cout << head->data << ", ";
		head = head->next;
	}
	cout << endl;
}

void empty(struct linked_list *head){
	struct linked_list *current, *prev;
	current = head;
	while(current != NULL){
		prev = current;
		current = current->next;
		delete prev;
	}
}
