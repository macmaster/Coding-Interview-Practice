/* Cracking the Coding Interview
 * Chapter: 1
 * Problem: 2
 * "Write code to reverse a C-Style 
   String (C-String means that “abcd” is represented as 
   five characters, including the null character)"
 * Author : Ronny Macmaster
 * Date : 12/17/15                                       */
 
#include <iostream>
#include <cstring>

using namespace std; 

char* reverse(char s[]){
   int n = 0; char t;
   while(s[n] != '\0')
      n++;
   for(int i = 0; i < n/2; i++){     
      t = s[i];
      s[i] = s[n-i-1];
      s[n-i-1] = t;
   }
   return s;
}

int main(){
  char array[7][30] = {"Hello", "TTYS", "abcdefghijklmnopqrstuvwxyz", "12d3", "A", "6", ""};
  for(int i = 0; i < 7; i++){
     cout << array[i] << ": "; cout << reverse(array[i]) << endl;
  }
}

