// 1 Develop a Menu driven program to demonstrate the following operations of Arrays
// ——MENU——- 1.CREATE
// 2. DISPLAY
// 3. INSERT
// 4. DELETE
// 5. LINEAR SEARCH
// 6. EXIT
#include<iostream>
using namespace std;
int big_arr[100];
int size;
int arr;
void create(){
cout <<"Enter the number of elements: ";
cin>> size;
if (size>100 || size<1)
{
    cout<<"Array size uncertain try again with a different number";
    return ;
}
cout<<"Enter the elements: ";
for (int i = 0; i < size; i++)
{
    cout<<"Element number " <<i+1<< ": ";
   cin>>big_arr[i];
}
};
void display(){
    cout<<"The given array is: ";
    for( int i=0;i<size;i++){
      cout << big_arr[i] << " ";

    }
};
void insert(){
    int new_number;
    int position;
   cout << "Enter the position of new element (1 to " << size + 1 << "): ";
    cin>>position;
    if(position>100 || position<1){
        cout<<"Invalid choice";
        return ;
    }
    cout<<"Enter the new number: ";
    cin>>new_number;
    for(int i=size;i>=position;i--){
        big_arr[i]=big_arr[i-1];
    }
    big_arr[position-1]=new_number;
    size++;
    cout<<"New number added succesfully";
}
void remove(){
    int position;
    cout<<"Enter the position of element that needs to be removed";
    cin>>position;
    if(position>size || position<1){
        cout<<"Invalid postion";
    }

    for (int i = position - 1; i < size - 1; i++) {
    big_arr[i] = big_arr[i + 1];
}

    size--;
}
void linear_search(){
    int number;
    cout<<"Enter the number which you want to search";
    cin>>number;
    int statement=0;
    for (int i = 0; i < size; i++)
    {
        if(number==big_arr[i]){
            cout<<"Number found at position: "<<i+1<<endl;
            statement=1;
        }
    }
    if(statement==0){
        cout<<"Number not found";
    }
}
    int main() {
    int choice;
    do {
        cout << "\nDisplay Menu\n";
        cout << "1. Create\n";
        cout << "2. Display all elements\n";
        cout << "3. Insert Element\n";
        cout << "4. Remove Element\n";
        cout << "5. Linear Search\n";
        cout << "6. Exit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                remove();
                break;
            case 5:
                linear_search();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
    
