// q3_middle.cpp
#include <iostream>
using namespace std;

struct Node{
 int v;
 Node* next;
 Node(int x){ v=x; next=NULL; }
};

Node* build(int a[],int n){
 Node *h=NULL,*t=NULL;
 for(int i=0;i<n;i++){
  Node* p=new Node(a[i]);
  if(!h) h=t=p;
  else{ t->next=p; t=p; }
 }
 return h;
}

int mid(Node* h){
 Node *s=h, *f=h;
 while(f && f->next){
  s=s->next;
  f=f->next->next;
 }
 return s->v;
}

int main(){
 int a[]={1,2,3,4,5};
 Node* head=build(a,5);

 cout<<"Middle = "<<mid(head)<<"\n";
 return 0;
}
