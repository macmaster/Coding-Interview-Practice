/* Cracking the Coding Interview
 * Chapter: 1
 * Problem: 1
 * "Implement  an  algorithm  to  determine  if  a 
   string  has  all  unique  characters
   What  if you can not use additional data structures?"
 * Author : Ronny Macmaster
 * Date : 12/17/15                                       */
 
#include <iostream>
#include <string>

using namespace std; 

bool unique(string s){
   for(int i = 0; i < s.length(); i++)
     for(int j = i+1; j < s.length(); j++)
      if(s[i] == s[j])
         return false;
   return true;
}

int main(){
  string array[6] = {"Hello", "TTYS", "abcdefghijklmnopqrstuvwxyz", "12d3", "A", "6"};
  string result[6];
  
  for(int i = 0; i < 6; i++){
   if(unique(array[i]))
      result[i] = "true";
   else
      result[i] = "false";
   cout << array[i] << ": " << result[i] << endl;
  }
}
