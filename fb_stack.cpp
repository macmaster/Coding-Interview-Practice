/* Facebook Stack Problem
 * 
 * Problem:
   "Given a stack of integers, reverse the values at the odd indices.
   Example: [0,1,2,3,4,5,6,7,8] becomes [0,7,2,5,4,3,6,1,8].
   There are no guarantees as to the contents of the stack, and you
   may only use ONE stack as auxiliary storage.
 *
 * Author : Ronny Macmaster
 * Date : 12/17/15                                       */
 
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template<typename type>
void print(stack<type> s){
   while(!s.empty()){
     cout << s.top() << ", ";
     s.pop();
   }
   cout << endl;
}

int main(){
   vector<int> v = {0,1,2,3,4,5,6,7,8};
   stack<int> s, s1, s2; 
   
   for(int i = 0; i < v.size(); i++)
      s.push(v[i]);
   
   
   cout << "Original:\t";
   print<int>(s);
   
   for(int i = 0, n = s.size(); i < n; i++){
      s1.push(s.top());
      s.pop();
   }
   
   for(int i = 0, n = s1.size(); i < n; i++){
      s.push(s1.top());
      if(i&0x01)
         s2.push(s1.top());
      s1.pop();
   }
   for(int i = 0, n = s.size(); i < n; i++){
      s1.push(s.top());
      s.pop();
   }
   
   for(int i = 0, n = s1.size(); i < n; i++){
      if(i&0x01){
         s.push(s2.top());
         s2.pop();s1.pop();
      }
      else{
         s.push(s1.top());
         s1.pop();
      }
   }
   
   
   cout << "Result:\t\t";
   print<int>(s);

 
}
