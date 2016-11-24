/** queue.cpp
 * Implementation of a Queue in C++
 * Uses a Linked List
 *
 * Ronald Macmaster
 */
 
 #include <list>
 #include "queue.h"

 template <typename T>
 Queue<T>::Queue(){
	queue = {};
	capacity = 0;
 }

 template <class T>
 T Queue<T>::front(){
 	if(capacity > 0){
		return queue.front();
	} else{
		return 0;
	}
 }
 
 template <class T>
 T Queue<T>::back(){
 	if(capacity > 0){
		return queue.back();
	} else{
		return 0;
	}
 }

 template <class T>
 int Queue<T>::size(){
 	return capacity;
 }

 template <class T>
 bool Queue<T>::empty(){
 	return capacity <= 0;
 }

 template <class T>
 void Queue<T>::enqueue(T object){
 	queue.push_back(object);
	capacity = capacity + 1;
 }

 template <class T>
 T Queue<T>::dequeue(){
 	if(capacity > 0){
		capacity = capacity - 1;
	 	return queue.pop_front();
	} else{ // null
		return 0;
	}
 }



