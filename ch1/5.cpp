/* Cracking the Coding Interview
 * Chapter: 1
 * Problem: 5
 * "Write a method to replace all spaces in a 
   string with ‘%20’"
 * Author : Ronny Macmaster
 * Date : 12/17/15                                       */

#include <iostream>
#include <cstring>

using namespace std; 

char* space(char s[]){
   int n = 0;
   while(s[n] != '\0')
      n++;
   for(int i = 0; i < n; i++)     
   	if(s[i] == ' '){
   		n += 2;
   		for(int j = n-1; j > i; j--)
   			s[j] = s[j-2];
   		s[i] = '%';
   		s[i+1] = '2';
   		s[i+2] = '0';
   	}
   return s;
}

int main(){
  char array[6][100] = {"Go to The store", "Welcome to Philidelphia", "GotoThestore", "2", "", "   Told You   "};
  for(int i = 0; i < 6; i++){
     cout << array[i] << ": "; cout << space(array[i]) << endl;
  }
}

