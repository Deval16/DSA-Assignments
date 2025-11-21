#include <iostream>
using namespace std;

struct PQueue {
    int *A;
    int capacity;
    int sz;
    PQueue(int cap){
        capacity = cap;
        A = new int[cap];
        sz = 0;
    }
    ~PQueue(){ delete[] A; }

    void swapI(int &x,int &y){ int t=x; x=y; y=t; }

    void siftUp(int i){
        while(i>0){
            int parent = (i-1)/2;
            if(A[parent] < A[i]){ swapI(A[parent], A[i]); i = parent; }
            else break;
        }
    }

    void siftDown(int i){
        while(true){
            int l = 2*i + 1;
            int r = 2*i + 2;
            int largest = i;
            if(l < sz && A[l] > A[largest]) largest = l;
            if(r < sz && A[r] > A[largest]) largest = r;
            if(largest != i){ swapI(A[i], A[largest]); i = largest; }
            else break;
        }
    }

    bool empty(){ return sz==0; }
    bool full(){ return sz==capacity; }

    // insert key
    bool push(int key){
        if(full()) return false;
        A[sz] = key;
        siftUp(sz);
        sz++;
        return true;
    }

    // peek max
    int top(){
        if(empty()) return -1; // sentinel - change per need
        return A[0];
    }

    // extract max
    int pop(){
        if(empty()) return -1;
        int ret = A[0];
        A[0] = A[sz-1];
        sz--;
        if(sz>0) siftDown(0);
        return ret;
    }

    // build heap from array (in-place)
    void buildFromArray(int arr[], int n){
        if(n > capacity) n = capacity; // simple guard
        for(int i=0;i<n;i++) A[i] = arr[i];
        sz = n;
        for(int i = (sz/2)-1; i>=0; --i) siftDown(i);
    }

    void show(){
        for(int i=0;i<sz;i++){ cout<<A[i]; if(i<sz-1) cout<<" "; }
        cout<<"\n";
    }
};

int main(){
    PQueue q(100);
    q.push(20); q.push(5); q.push(30); q.push(15);
    cout<<"Heap array form: "; q.show();
    cout<<"Top = "<<q.top()<<"\n";
    cout<<"Pop: "<<q.pop()<<"\n";
    cout<<"Now top = "<<q.top()<<"\n";

    // build from array demo
    int arr[] = {3,1,4,1,5,9,2};
    PQueue q2(20);
    q2.buildFromArray(arr, 7);
    cout<<"Built heap: "; q2.show();
    cout<<"Extract all: ";
    while(!q2.empty()) cout<<q2.pop()<<" ";
    cout<<"\n";
    return 0;
}
