// Design the Logic to Find a Missing Number in a Sorted Array. 


#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = 6; // numbers are from 1 to 6
    int total = n * (n + 1) / 2;

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum =sum+ arr[i];
    }

    cout << "Missing number: " << total - sum << endl;
    return 0;
}
