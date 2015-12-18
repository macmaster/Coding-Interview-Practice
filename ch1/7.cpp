/* Cracking the Coding Interview
 * Chapter: 1
 * Problem: 7
 * "Write an algorithm such that if an element in an MxN 
   matrix is 0, its entire row and 
   column is set to 0"
 * Author : Ronny Macmaster
 * Date : 12/17/15                                       */

#include <iostream>
#include <cstring>

using namespace std; 

bool **plot(int **data, int row_size, int col_size){
   bool **graph = new bool*[row_size];
   for(int i = 0; i < row_size; i++)
      graph[i] = new bool[col_size]; 
   
   for(int i = 0; i < row_size; i++)
      for(int j = 0; j < col_size; j++)
         graph[i][j] = data[i][j] ? true : false; //create a plot of 0s 
   
   return graph;
}

void zero(int **data, int row, int col, int row_size, int col_size){
   for(int i = 0; i < row_size; i++)
      data[i][col] = 0;
   for(int j = 0; j < col_size; j++)
      data[row][j] = 0;
}


template <typename type>
void print(type **pixel, int row_size, int col_size){
   for(int i = 0; i < row_size; i++){
      for(int j = 0; j < col_size; j++)
         cout << pixel[i][j] << ' ';
      cout << endl;
   }
}
int main(){
   const int m = 5, n = 5; 
   //int k = 0;
   
   int junk[m][n] = {
      {0,1,2,3,7},
      {1,4,5,1,3},
      {5,675,1,44,5},
      {5,4,1,1,1},
      {4,3,1,1,1}
   };

   int **pixels = new int*[m];
   for(int i = 0; i < m; i++)
      pixels[i] = new int[n];

   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
         pixels[i][j] = junk[i][j];
   
   cout << "Data: " << endl;
   print<int>(pixels, m, n);

   cout << "Graph: " << endl;
   bool **graph = plot(pixels, m, n);
   print<bool>(graph, m, n);
   
   cout << "Result: " << endl;
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
         if(!graph[i][j])
            zero(pixels, i, j, m, n);
   print<int>(pixels, m, n);
   
   for(int i = 0 ; i < m; i++)
      delete [] graph[i];
   delete [] graph;   

   for(int i = 0 ; i < m; i++)
      delete [] pixels[i];
   delete [] pixels;   

}

