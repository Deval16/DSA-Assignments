
//Design the logic to remove the duplicate elements from an Array and after the deletion the array should contain the unique elements.


#include<iostream>
using namespace std;
int main (){
    int Question_2;
int arr[100];
int elements;
cout<<"Enter number of elements in the array";
cin >> elements;
cout<<"Enter the elements: ";
for(int i=0;i<elements;i++){
    cin>> arr[i];
}
cout<<"The given array is: ";
for(int i=0;i<elements;i++){
    cout<< arr[i] ;
}
int position;
for (int i = 0; i < elements; i++)
{
for (int j = i+1; j < elements; j++)
{
    if(arr[i]==arr[j]){
    for(int k=j;k<elements;k++){
        arr[k]=arr[k+1];
    }
    elements--;
    }
  else{j++;}
}
}


cout<<"The new array is: "
for(int i=0;i<elements;i++){
cout<< arr[i];
}
return 0;
}







