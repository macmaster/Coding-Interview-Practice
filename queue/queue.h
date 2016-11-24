/** queue.h
 * Implementation of a Queue in C++
 *
 * Ronald Macmaster
 */
 
 #include <list>

 template <typename T>
 class Queue{
 	
  private:
	int capacity; 
	std::list<T> queue;
	
  public:  
  	Queue<T>();
	T front();
	T back();
	int size();
	bool empty();
	void enqueue(T object);
	T dequeue();
 };
