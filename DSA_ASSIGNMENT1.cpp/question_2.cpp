#include<iostream>
using namespace std;
int main(){
    int  arr[100];
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    cout<<"Enter your array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"The array is:  ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<< " ";
    }
    cout<<"\n";
    int x=0;
    for (int i = 0; i < size; i++){
for(int j=i+1;j<size;j++){
    if(arr[i]==arr[j]){
        cout<<"Repetition spotted \n";
         for(int k=j;k<size;k++){
         arr[k]=arr[k+1];
        

    }
    size--;
}
else{j++;}
    
    }
    
        
    }
      cout<<"The new array is:";
    for (int i = 0; i < size; i++)
    {
      cout<<arr[i];
    }
    
}


