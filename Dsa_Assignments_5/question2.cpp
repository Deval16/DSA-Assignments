
#include <iostream>
using namespace std;

struct Node{
 int v;
 Node* next;
 Node(int x){ v=x; next=NULL; }
};

Node* build(int arr[],int n){
 Node *h=NULL,*t=NULL;
 for(int i=0;i<n;i++){
  Node* p=new Node(arr[i]);
  if(!h) h=t=p;
  else{ t->next=p; t=p; }
 }
 return h;
}

int countOcc(Node* h,int key){
 int c=0;
 while(h){
  if(h->v==key) c++;
  h=h->next;
 }
 return c;
}

Node* delAll(Node* h,int key){
 while(h && h->v==key){
  Node* t=h;
  h=h->next;
  delete t;
 }
 if(!h) return NULL;

 Node* p=h;
 while(p->next){
  if(p->next->v==key){
   Node* t=p->next;
   p->next=t->next;
   delete t;
  } else p=p->next;
 }
 return h;
}

void print(Node* h){
 while(h){
  cout<<h->v;
  if(h->next) cout<<"->";
  h=h->next;
 }
 cout<<"\n";
}

int main(){
 int a[]={1,2,1,2,1,3,1};
 Node* head=build(a,7);

 cout<<"Before: "; print(head);
 int key=1;
 cout<<"Count = "<<countOcc(head,key)<<"\n";

 head=delAll(head,key);
 cout<<"After: "; print(head);

 return 0;
}
