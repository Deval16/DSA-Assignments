// circ_show_repeat.cpp
#include <iostream>
using namespace std;
struct Node{ int v; Node* next; Node(int x){ v=x; next=NULL; } };

Node* build(int a[], int n){
 Node* tail=NULL;
 for(int i=0;i<n;i++){
  Node* p=new Node(a[i]);
  if(!tail){ tail=p; p->next=p; } else { p->next = tail->next; tail->next=p; tail=p; }
 }
 return tail;
}

void showRepeat(Node* tail){
 if(!tail){ cout<<"Empty\n"; return; }
 Node* p=tail->next; // head
 do{
  cout<<p->v<<" ";
  p=p->next;
 } while(p!=tail->next);
 // print head again
 cout<<tail->next->v<<"\n";
}

int main(){
 int a[]={20,100,40,80,60};
 Node* tail = build(a,5);
 showRepeat(tail); // prints: 20 100 40 80 60 20
 return 0;
}
