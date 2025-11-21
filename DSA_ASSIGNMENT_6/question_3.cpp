// sizes.cpp
#include <iostream>
using namespace std;

struct D{ int v; D* prev; D* next; D(int x){ v=x; prev=NULL; next=NULL; } };
int sizeD(D* h){
 int c=0;
 while(h){ c++; h=h->next; }
 return c;
}

struct C{ int v; C* next; C(int x){ v=x; next=NULL; } };
int sizeC(C* tail){
 if(!tail) return 0;
 int c=0;
 C* p=tail->next;
 do{ c++; p=p->next; } while(p!=tail->next);
 return c;
}

int main(){
 // example
 D* d1=new D(1); D* d2=new D(2); d1->next=d2; d2->prev=d1;
 C* ctail=new C(10); C* c2=new C(20); ctail->next=ctail; // one node
 // build small lists quickly
 cout<<"Size Doubly = "<< sizeD(d1) <<"\n"; // 2
 cout<<"Size Circular = "<< sizeC(ctail) <<"\n"; // 1
 return 0;
}
