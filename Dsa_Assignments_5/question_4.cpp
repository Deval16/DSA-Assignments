// q4_reverse.cpp
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
  else { t->next=p; t=p; }
 }
 return h;
}

Node* rev(Node* h){
 Node *prev=NULL, *cur=h, *nxt=NULL;
 while(cur){
  nxt=cur->next;
  cur->next=prev;
  prev=cur;
  cur=nxt;
 }
 return prev;
}

void show(Node* h){
 while(h){
  cout<<h->v;
  if(h->next) cout<<"->";
  h=h->next;
 }
 cout<<"->NULL\n";
}

int main(){
 int a[]={1,2,3,4};
 Node* head=build(a,4);

 cout<<"Before: "; show(head);
 head=rev(head);
 cout<<"After:  "; show(head);

 return 0;
}
