/* Cracking the Coding Interview
 * Chapter: 1
 * Problem: 8
 * "Assume  you  have  a  method  isSubstring  which  checks  if  one  word  is  a  substring  of another
   Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using 
   only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”)"
 * Author : Ronny Macmaster
 * Date : 12/17/15                                       */

#include <iostream>
#include <cstring>

using namespace std; 

bool isSubstring(string str, string substr){
   size_t pos = str.find(substr);
   if(pos != string::npos)
      return true;
   else
      return false;
}

bool isRotation(string s1, string s2){
   if(s1.length() != s2.length())
      return false;
   else
      return isSubstring(s1 + s1, s2);
}

int main(){
   /* isSubstring() Test */
   /* cout << isSubstring("HelloWorld", "World") << isSubstring("HelloWorld", h) << isSubstring("HelloWorld", "good") << isSubstring("HelloWorld",
        "Hello") << isSubstring("HelloWorld", "ldHe") << isSubstring("HelloWorld", "W"); */
   
   cout << (isRotation("waterbottle", "erbottlewat") ? "true" : "false") << endl;
   
        
}

