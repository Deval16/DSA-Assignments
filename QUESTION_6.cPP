// //6) Write a program to implement the following operations on a Sparse Matrix, assuming the 
// matrix is represented using a triplet. 

#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

int main() {
    int n = 4;
    Element A[] = {{0,0,5}, {0,2,8}, {1,1,3}, {2,3,6}};
    int size = 4;

    cout << "Original Triplet:\n";
    for (int i=0; i<size; i++)
        cout << A[i].row << " " << A[i].col << " " << A[i].val << endl;

    cout << "\nTranspose Triplet:\n";
    for (int i=0; i<size; i++)
        cout << A[i].col << " " << A[i].row << " " << A[i].val << endl;

    return 0;
}
