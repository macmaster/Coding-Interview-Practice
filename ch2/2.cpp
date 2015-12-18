/* Cracking the Coding Interview
 * Chapter: 1
 * Problem: 2
 * "Implement an algorithm to find the nth to last element of a singly linked list"
 * Author : Ronny Macmaster
 * Date : 12/17/15                                       */

#include <iostream>
#include <stdexcept>
#include <list>
#include <map>

using namespace std;

template <typename type>
void remove_rn(list<type> &l, int n){
	typename list<type>::reverse_iterator ritr = l.rbegin();
	while(n){
		ritr++; n--;
	}
	l.erase((++ritr).base());
}

template <typename type>
void print(list<type> l){
	for(typename list<int>::iterator itr = l.begin(); itr != l.end(); itr++)
			cout << *itr << ", ";
	cout << endl; 
}

int main(){

	list<int> data = /*{1,2,3,4,5}*/{0,8,8,9,4,4,6,3,1,2,2,2,2,2,3,3,4,4,5,5,6,6,6,7,7};
	list<char> letters = {'a', 'b', '6', '7', 'u', '4', '5', 'a', 'K', 'K', 'L',};
	
	cout << "Before Removal: ";
	print<int>(data);
	
	cout << "After Removal: ";
	remove_rn<int>(data, 8);
	print<int>(data);
	
}
