// 1 Develop a Menu driven program to demonstrate the following operations of Arrays
// ——MENU——- 1.CREATE
// 2. DISPLAY
// 3. INSERT
// 4. DELETE
// 5. LINEAR SEARCH
// 6. EXIT
#include <iostream>
using namespace std;

const int max_size = 100;
int arr[max_size];
int size = 0;

void create() {
    cout << "Enter the number of elements: ";
    cin >> size;
    if (size > max_size) {
        cout << "The number of elements entered exceed the maximum allowed (" << max_size << "). Setting size to " << max_size << ".\n";
        size = max_size;
    }
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void display() {
    if (size == 0) {
        cout << "There are no elements entered\n";
        return;
    }
    cout << "The elements are: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insert() {
    if (size == max_size) {
        cout << "Array is full, cannot insert more elements.\n";
        return;
    }
    int element, position;
    cout << "Enter the element: ";
    cin >> element;
    cout << "Enter the position at which it has to be entered (0 to " << size << "): ";
    cin >> position;

    if (position < 0 || position > size) {
        cout << "Element cannot be entered here\n";
        return;
    }

    // Shift elements to the right
    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }

    arr[position] = element;
    size++;
    cout << "Element inserted successfully.\n";
}

void remove() {
    if (size == 0) {
        cout << "Array is empty, nothing to delete.\n";
        return;
    }
    int position;
    cout << "Enter the position of element that needs to be deleted (0 to " << size - 1 << "): ";
    cin >> position;

    if (position < 0 || position >= size) {
        cout << "Invalid position!\n";
        return;
    }

    int deleted = arr[position];
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element " << deleted << " deleted from position " << position << ".\n";
}

void linear_search() {
    if (size == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int element;
    cout << "Enter the element you want to find: ";
    cin >> element;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            cout << "Element found at position " << i << ".\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Element " << element << " is not found in the array.\n";
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
