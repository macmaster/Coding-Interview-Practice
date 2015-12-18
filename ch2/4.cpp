/* Cracking the Coding Interview
 * Chapter: 1
 * Problem: 4
 * "You have two numbers represented by a linked list, where each node contains a single digit
  The digits are stored in reverse order, such that the 1’s digit is at the head of the list
  Write a function that adds the two numbers and returns the sum as a linked list
	EXAMPLE 
	Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
	Output: 8 -> 0 -> 8"
 * Author : Ronny Macmaster
 * Date : 12/17/15                                       */

#include <iostream>

using namespace std;

struct linked_list{
	int data;
	struct linked_list *next;
};

void print(struct linked_list *head);
void empty(struct linked_list *head);

/* Adds the two numbers together */
struct linked_list *add(struct linked_list *num1, struct linked_list *num2);

int main(){
	int data1[3] ={0,1,2};
	int data2[3] ={0,1,2};
	struct linked_list *current, *prev, *num1, *num2, *sum;
	
	// build first number
	current = num1 = new struct linked_list;
	for(int i = 0; i < 3; i++){
		current->data = data1[i];
		current->next = new struct linked_list;
		prev = current;
		current = current->next;
	}
	delete prev->next; prev->next = NULL;
		
	// build second number
	current = num2 = new struct linked_list;
	for(int i = 0; i < 3; i++){
		current->data = data2[i];
		current->next = new struct linked_list;
		prev = current;
		current = current->next;
	}
	delete prev->next; prev->next = NULL;	
	
	// Print Results	
	cout << "Before add (num1): "; print(num1);
	cout << "Before add (num2): "; print(num2);
	
	sum = add(num1, num2);
	
	cout << "After add (num1): "; print(num1);
	cout << "After add (num2): "; print(num2);
	
	cout << "Sum: "; print(sum);
	
	// Empty All Numbers
	empty(num1), empty(num2), empty(sum);
	
}

struct linked_list *add(struct linked_list *num1, struct linked_list *num2){
	struct linked_list *sum = NULL; // empty represents 0;
	struct linked_list *current, *prev;
	int total = 0, digit = 1;
	
	// build total
	while((num1 != NULL) || (num2 != NULL)){
		if(num1 != NULL){
			total += num1->data*digit;
			num1 = num1->next;
		}
		if(num2 != NULL){
			total += num2->data*digit;
			num2 = num2->next;
		}
		digit *= 10;
	}
	
	if(total == 0)
		return sum;
	
	current = sum = new struct linked_list;
	while(total > 0){
		current->data = total%10;
		current->next = new struct linked_list;
		prev = current;
		total /= 10;
		current = current->next;
	}
	delete prev->next; prev->next = NULL;
	
	return sum;	
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

/* Recursion Sketching
struct linked_list *plu(struct linked_list *num1, struct linked_list *num2){
	
	struct linked_list *sum = NULL; // empty represents 0;
	if((num1 == NULL) && (num2 == NULL))
		return sum;
	else{
		sum = new struct linked_list;
		sum->data = 0;
		if(num1 != NULL){
			sum->data += num1->data;
			num1 = num1->next;
		}
		if(num2 != NULL){
			sum->data += num2->data;
			num2 = num2->next;
		}
		sum->next = add(num1, num2);
		return sum;
	}
}*/
