// 4) Implement the logic to
// a. Reverse the elements of an array
// b. Find the matrix multiplication
// c. Find the Transpose of a Matrix

#include<iostream>
#include<vector>
using namespace std;
int main (){
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
int row1,column1;
int arr1[row1][column1];
cout<<"Enter number of rows: ";
cin>>row1;
cout<<"Enter the number of columns";
cin<<column1;
for(int i=0;i<row1;i++){
    for(int j=0;j<column1;j++){
        cout<<"Enter element number [" <<i<< ","<<j<<"]" ;
        cin>>arr1[i][j];
    }
}
cout<<"The first given matrix is: ";
for(int i=0;i<row1;i++){
    for(int j=0;j<column1;j++){
        cout<<arr1[i][j];
}

}
int row2,column2;
int arr2[row2][column2];
for(int i=0;i<row2;i++){
    for(int j=0;j<column2;j++){
        cout<<"Enter element number [" <<i<< ","<<j<<"]" ;
        cin>>arr2[i][j];
    }
}
cout<<"The second given matrix is: ";
for(int i=0;i<row2;i++){
    for(int j=0;j<column2;j++){
        cout<<arr2[i][j];
}
}
if(column1==row2){
cout<<"On multiplying both the matrices we get: ";
vector<vector<int>> C(row1,vector<int>(column2,0));
for(int i=0;i<rowl;i++){
    for(int j=0;j<column2;j++)
    for(int k=0;k<column1;k++){
        C[i][j] += A[i][k]* B[k][j];
    }
    
}
}
cout << "Resultant Matrix C:\n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}




