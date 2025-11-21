#include <iostream>
using namespace std;

void swapInt(int &a,int &b){ int t=a; a=b; b=t; }

// max-heapify for subtree rooted at i, n = heap size
void maxHeapify(int A[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && A[l] > A[largest]) largest = l;
    if(r < n && A[r] > A[largest]) largest = r;
    if(largest != i){
        swapInt(A[i], A[largest]);
        maxHeapify(A, n, largest);
    }
}

// min-heapify
void minHeapify(int A[], int n, int i){
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && A[l] < A[smallest]) smallest = l;
    if(r < n && A[r] < A[smallest]) smallest = r;
    if(smallest != i){
        swapInt(A[i], A[smallest]);
        minHeapify(A, n, smallest);
    }
}

void buildMaxHeap(int A[], int n){
    for(int i = n/2 - 1; i >= 0; --i) maxHeapify(A, n, i);
}
void buildMinHeap(int A[], int n){
    for(int i = n/2 - 1; i >= 0; --i) minHeapify(A, n, i);
}

// increasing order (ascending): use max-heap
void heapSortAsc(int A[], int n){
    buildMaxHeap(A,n);
    for(int i=n-1;i>0;--i){
        swapInt(A[0], A[i]);
        maxHeapify(A, i, 0); // heap size reduces
    }
}

// decreasing order (descending): use min-heap
void heapSortDesc(int A[], int n){
    buildMinHeap(A,n);
    for(int i=n-1;i>0;--i){
        swapInt(A[0], A[i]);
        minHeapify(A, i, 0);
    }
}

void printArr(int A[], int n){
    for(int i=0;i<n;i++){ cout<<A[i]; if(i<n-1) cout<<" "; }
    cout<<"\n";
}

int main(){
    int a1[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(a1)/sizeof(a1[0]);

    cout<<"Original: "; printArr(a1,n);

    int b[n];
    for(int i=0;i<n;i++) b[i]=a1[i];

    heapSortAsc(b,n);
    cout<<"Sorted ascending: "; printArr(b,n);

    for(int i=0;i<n;i++) b[i]=a1[i];
    heapSortDesc(b,n);
    cout<<"Sorted descending: "; printArr(b,n);

    return 0;
}
