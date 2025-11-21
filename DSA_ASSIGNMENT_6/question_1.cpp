// dbl_menu.cpp
#include <iostream>
using namespace std;

struct Node{
 int val;
 Node* prev;
 Node* next;
 Node(int x){ val=x; prev=NULL; next=NULL; }
};

void show(Node* h){
 if(!h){ cout<<"Empty\n"; return; }
 Node* p=h;
 while(p){
  cout<<p->val;
  if(p->next) cout<<" <-> ";
  p=p->next;
 }
 cout<<"\n";
}

void insertFirst(Node*& h,int x){
 Node* n=new Node(x);
 if(!h){ h=n; return; }
 n->next=h; h->prev=n; h=n;
}

void insertLast(Node*& h,int x){
 Node* n=new Node(x);
 if(!h){ h=n; return; }
 Node* p=h;
 while(p->next) p=p->next;
 p->next=n; n->prev=p;
}

bool insertAfter(Node* h,int key,int x){
 Node* p=h;
 while(p && p->val!=key) p=p->next;
 if(!p) return false;
 Node* n=new Node(x);
 n->next=p->next;
 n->prev=p;
 if(p->next) p->next->prev=n;
 p->next=n;
 return true;
}

bool insertBefore(Node*& h,int key,int x){
 if(!h) return false;
 if(h->val==key){ insertFirst(h,x); return true; }
 Node* p=h;
 while(p && p->val!=key) p=p->next;
 if(!p) return false;
 Node* n=new Node(x);
 n->prev=p->prev;
 n->next=p;
 p->prev->next=n;
 p->prev=n;
 return true;
}

bool deleteNode(Node*& h,int key){
 if(!h) return false;
 Node* p=h;
 while(p && p->val!=key) p=p->next;
 if(!p) return false;
 if(p==h){
  h=h->next;
  if(h) h->prev=NULL;
  delete p;
  return true;
 }
 if(p->next) p->next->prev=p->prev;
 if(p->prev) p->prev->next=p->next;
 delete p;
 return true;
}

int search(Node* h,int key){
 int pos=1;
 while(h){
  if(h->val==key) return pos;
  h=h->next; pos++;
 }
 return -1;
}

int main(){
 Node* head=NULL;
 int ch,x,k;
 do{
  cout<<"\n1:InsFirst 2:InsLast 3:InsAfter 4:InsBefore 5:DelKey 6:Search 7:Show 0:Exit\nChoice: ";
  if(!(cin>>ch)) return 0;
  switch(ch){
   case 1: cout<<"val: "; cin>>x; insertFirst(head,x); break;
   case 2: cout<<"val: "; cin>>x; insertLast(head,x); break;
   case 3: cout<<"after which? "; cin>>k; cout<<"val: "; cin>>x;
           if(!insertAfter(head,k,x)) cout<<"Not found\n"; break;
   case 4: cout<<"before which? "; cin>>k; cout<<"val: "; cin>>x;
           if(!insertBefore(head,k,x)) cout<<"Not found\n"; break;
   case 5: cout<<"del val: "; cin>>k; cout<<(deleteNode(head,k)? "Deleted\n":"Not found\n"); break;
   case 6: cout<<"search val: "; cin>>k; cout<<(search(head,k)==-1?"Not found\n":"Found\n"); break;
   case 7: show(head); break;
  }
 } while(ch!=0);
 return 0;
}
