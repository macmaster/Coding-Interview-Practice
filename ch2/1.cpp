/* Cracking the Coding Interview
 * Chapter: 1
 * Problem: 1
 * "Write code to remove duplicates from an unsorted linked list
	FOLLOW UP
	How would you solve this problem if a temporary buffer is not allowed?"
 * Author : Ronny Macmaster
 * Date : 12/17/15                                       */

#include <iostream>
#include <stdexcept>
#include <list>
#include <map>

using namespace std;

template <typename type>
void remove_duplicates(list<type> &l){
	
	map<type, typename list<type>::iterator> m;

	for(typename list<type>::iterator itr = l.begin(); itr != l.end(); itr++){
		
		try{
			m.at(*itr);
			itr = --l.erase(itr);
		}
		catch(out_of_range &oor){
			m[*itr] = itr;
		}
	}
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
	
	remove_duplicates<int>(data);
	print<int>(data);
	
	remove_duplicates<char>(letters);
	print<char>(letters);
	
	
}
