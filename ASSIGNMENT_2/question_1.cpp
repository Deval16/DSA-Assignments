// 1) Implement the Binary search algorithm regarded as a fast search algorithm with run-time 
// complexity of Ο(log n) in comparison to the Linear Search. 



#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int elements;
    int n;
    
    cout<<"Enter the no of elements you want to enter in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //First sort the elements in ascending order
    sort(arr, arr + n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    //Now create variables for swapping
    int key,low,mid,high;
    cout<<"Enter the number you want to find from the given array: ";
    cin>> key;
low=0;
high=n-1;
mid=(high+low)/2;
while (low<=high){
    mid=(high+low)/2;
    if(key==arr[mid]){
        return mid;
    }
    if(key>arr[mid]){
        low=mid+1;
    }
    if(key<arr[mid]){
        high=mid-1;
    }
} 
return 0;
}