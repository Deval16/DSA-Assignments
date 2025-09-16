
// Write a program to find sum of every row and every column in a two-dimensional array

#include<iostream>
using namespace std;
int main() {
    int row1, column1;
    cout << "Enter number of rows for the matrix: ";
    cin >> row1;
    cout << "Enter number of columns for the matrix: ";
    cin >> column1;

 int arr[row1][column1];
 for(int i=0;i<row1;i++){
    for(int j=0;j<column1;j++){
        cout << "Enter the element " << i+1 << "," << j+1 << ": ";
        cin >>arr[i][j];
    }
 }

 cout<<"The given matrix is:";
 cout<<"\n";

for(int i=0;i<row1;i++){
    for (int j=0;j<column1;j++){
    cout << arr[i][j] << " ";
    }
    cout << "\n";
}
for (int i = 0; i < row1; i++) {
    int rowSum = 0;
    for (int j = 0; j < column1; j++) {
        rowSum += arr[i][j];
    }
    cout << "Sum of row " << i+1 << " is " << rowSum << "\n";
}
for (int i = 0; i < column1; i++) {
    int columnSum = 0;
    for (int j = 0; j < row1; j++) {
        columnSum += arr[i][j];
    }
    cout << "Sum of column " << j+1 << " is " << columnSum << "\n";
}


}
