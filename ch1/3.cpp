/* Cracking the Coding Interview
 * Chapter: 1
 * Problem: 3
 * "Design  an  algorithm  and  write  code  to  
   remove  the  duplicate  characters  in  a 
   string without using any additional buffer
   NOTE: One or two additional variables are fine
   An extra copy of the array is not."
 * Author : Ronny Macmaster
 * Date : 12/17/15                                       */

#include <iostream>
#include <cstring>

using namespace std; 

char* remove(char s[]){
   int n = 0;
   while(s[n] != '\0')
      n++;
   for(int i = 0; i < n; i++)     
   	for(int j = i+1; j < n; j++)	
   		if(s[i] == s[j]){
   			for(int k = j; k < n; k++)
   				s[k] = s[k+1];
   				n--;j = i;
   			}
   return s;
}

int main(){
  char array[7][100] = {"HELLOhelohheeeeeeeeeeHHHHHHlllLLlllLLoohheelohellohellohellohelloheloohelloooooo", "TTYS", "abcdefghijklmnopqrstuvwxyz", "12d3", "A", "6", ""};
  for(int i = 0; i < 7; i++){
     cout << array[i] << ": "; cout << remove(array[i]) << endl;
  }
}

