// 4) Implement the logic to
// a. Reverse the elements of an array
// b. Find the matrix multiplication
// c. Find the Transpose of a Matrix

// #include<iostream>
// #include<vector>
// using namespace std;
// int main (){
    //A PART
// int arr[10];
// int elements;
// cout<<"Enter the number of elements in array: ";
// cin>>elements;
// cout<<"Enter " <<elements<<" numbers: ";
// for(int i=0;i<elements;i++){
//     cin>>arr[i];
// }
// cout<<"The given array is:\n ";
// for(int i=0;i<elements;i++){
//     cout<<arr[i];
 
// }
// cout<<"The reversed array is: \n";

// for(int j=elements-1;j>=0;j--){
//     cout<<arr[j];
   
// }
//BPART
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int row1, column1;
//     cout << "Enter number of rows for first matrix: ";
//     cin >> row1;
//     cout << "Enter number of columns for first matrix: ";
//     cin >> column1;

//     vector<vector<int>> arr1(row1, vector<int>(column1));
//     cout << "Enter elements of first matrix:\n";
//     for (int i = 0; i < row1; i++) {
//         for (int j = 0; j < column1; j++) {
//             cout << "Enter element [" << i << "," << j << "]: ";
//             cin >> arr1[i][j];
//         }
//     }

//     int row2, column2;
//     cout << "Enter number of rows for second matrix: ";
//     cin >> row2;
//     cout << "Enter number of columns for second matrix: ";
//     cin >> column2;

//     vector<vector<int>> arr2(row2, vector<int>(column2));
//     cout << "Enter elements of second matrix:\n";
//     for (int i = 0; i < row2; i++) {
//         for (int j = 0; j < column2; j++) {
//             cout << "Enter element [" << i << "," << j << "]: ";
//             cin >> arr2[i][j];
//         }
//     }

//     cout << "The first given matrix is:\n";
//     for (int i = 0; i < row1; i++) {
//         for (int j = 0; j < column1; j++) {
//             cout << arr1[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "The second given matrix is:\n";
//     for (int i = 0; i < row2; i++) {
//         for (int j = 0; j < column2; j++) {
//             cout << arr2[i][j] << " ";
//         }
//         cout << endl;
//     }

//     if (column1 != row2) {
//         cout << "Invalid combination of rows and columns for multiplication.\n";
//         return 0;
//     }

//     vector<vector<int>> C(row1, vector<int>(column2, 0));
// //This means creating a matrix C which has row1 and column2 as it's row and column
//     for (int i = 0; i < row1; i++) {
//         for (int j = 0; j < column2; j++) {
//             for (int k = 0; k < column1; k++) {
//                 C[i][j] += arr1[i][k] * arr2[k][j];
//             }
//         }
//     }
//     cout << "On multiplying both the matrices we get:\n";
//     for (int i = 0; i < row1; i++) {
//         for (int j = 0; j < column2; j++) {
//             cout << C[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
// }


//C part done
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
int arr2[column1][row1];
cout<<"The transpose of the matrix is: ";
 cout<<"\n";
 for(int i=0;i<column1;i++ ){
    for(int j=0;j<row1;j++){
        arr2[i][j]=arr[j][i];
    }
 }
 for(int i=0;i<column1;i++){
    for (int j=0;j<row1;j++){
cout << arr[i][j] << " ";
    }
    cout << "\n";
}

    
}