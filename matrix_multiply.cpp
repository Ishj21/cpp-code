#include <iostream>

using namespace std;
int main() {
  int first_matrix[10][10], second_matrix[10][10], result_matrix[10][10], row, column, i, j, k;
  cout << "enter the number of row = ";
  cin >> row;
  cout << "enter the number of column = ";
  cin >> column;
  cout << "enter the first matrix element =\n";
  for (i = 0; i < row; i++) {
    for (j = 0; j < column; j++) {
      cin >> first_matrix[i][j];
    }
  }
  cout << "enter the second matrix element = \n";
  for (i = 0; i < row; i++) {
    for (j = 0; j < column; j++) {
      cin >> second_matrix[i][j];
    }
  }
  cout << "multiply of the matrix = \n";
  for (i = 0; i < row; i++) {
    for (j = 0; j < column; j++) {
      result_matrix[i][j] = 0;
      for (k = 0; k < column; k++) {
        result_matrix[i][j] += first_matrix[i][k] * second_matrix[k][j];
      }
    }
  }
  //for printing result    
  for (i = 0; i < row; i++) {
    for (j = 0; j < column; j++) {
      cout << result_matrix[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
