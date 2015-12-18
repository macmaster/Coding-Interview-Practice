/* Cracking the Coding Interview
 * Chapter: 1
 * Problem: 6
 * "Given  an  image  represented  by  an  NxN 
   matrix,  where  each  pixel  in  the  image  is  4 
   bytes, write a method to rotate the image by 90 degrees
   Can you do this in place?
 * Author : Ronny Macmaster
 * Date : 12/17/15                                       */

#include <iostream>
#include <cstring>

using namespace std; 

void rotate(int **pixel, int row_size, int col_size, char dir){
   int buffer[col_size][row_size];
   if(dir == 'l'){
      for(int i = 0; i < col_size; i++)
         for(int j = 0; j < row_size; j++)
            buffer[col_size-i-1][j] = pixel[j][i]; // Transpose -> Vertical Reverse
      for(int i = 0; i < col_size; i++)
         for(int j = 0; j < row_size; j++)
            pixel[i][j] = buffer[i][j];      
   }
   else if(dir == 'r'){
      for(int i = 0; i < col_size; i++)
         for(int j = 0; j < row_size; j++)
            buffer[j][row_size-i-1] = pixel[i][j]; // Transpose -> Vertical Reverse
      for(int i = 0; i < col_size; i++)
         for(int j = 0; j < row_size; j++)
            pixel[i][j] = buffer[i][j];
   }
   else
      cerr << "Invalid Rotation Option!" << endl;
}

void print(int **pixel, int row_size, int col_size){
   for(int i = 0; i < row_size; i++){
      for(int j = 0; j < col_size; j++)
         cout << pixel[i][j] << ' ';
      cout << endl;
   }
}
int main(){
   const int m = 5, n = 5; 
   int k = 0;

   int **pixels = new int*[m];
   for(int i = 0; i < m; i++)
      pixels[i] = new int[n];

   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
         pixels[i][j] = k++;
   
   cout << "No rotation: " << endl;
   print(pixels, m, n);
   
   cout << "Left rotation: " << endl;
   rotate(pixels, m, n, 'l'); print(pixels, m, n);
   
   cout << "Back to Normal: " << endl;
   rotate(pixels, m, n, 'r'); print(pixels, m, n);
   
   cout << "Right Rotation: " << endl;
   rotate(pixels, m, n, 'r'); print(pixels, m, n);
   
   for(int i = 0 ; i < m; i++)
      delete [] pixels[i];
   delete [] pixels;   

}

