// circ_menu.cpp
#include <iostream>
using namespace std;

struct Node{ int v; Node* next; Node(int x){ v=x; next=NULL; } };

void show(Node* tail){
 if(!tail){ cout<<"Empty\n"; return; }
 Node* p = tail->next; // head
 do{
  cout<<p->v;
  p=p->next;
  if(p!=tail->next) cout<<" -> ";
 } while(p!=tail->next);
 cout<<"\n";
}

void insertAsFirst(Node*& tail,int x){
 Node* n=new Node(x);
 if(!tail){ tail=n; n->next=n; return; }
 n->next = tail->next;
 tail->next = n;
}

void insertAsLast(Node*& tail,int x){
 Node* n=new Node(x);
 if(!tail){ tail=n; n->next=n; return; }
 n->next = tail->next;
 tail->next = n;
 tail = n;
}

bool insertAfter(Node* tail,int key,int x){
 if(!tail) return false;
 Node* p=tail->next;
 do{
  if(p->v==key){
   Node* n=new Node(x);
   n->next=p->next;
   p->next=n;
   if(p==tail) tail = n; // if inserted after tail, new becomes tail
   return true;
  }
  p=p->next;
 } while(p!=tail->next);
 return false;
}

bool deleteNode(Node*& tail,int key){
 if(!tail) return false;
 Node *p=tail->next, *prev=tail;
 do{
  if(p->v==key){
   if(p==prev){ // only one node
    delete p; tail=NULL; return true;
   }
   prev->next = p->next;
   if(p==tail) tail = prev;
   if(p==tail->next) tail->next = prev->next;
   delete p;
   return true;
  }
  prev=p; p=p->next;
 } while(p!=tail->next);
 return false;
}

int search(Node* tail,int key){
 if(!tail) return -1;
 Node* p=tail->next; int pos=1;
 do{
  if(p->v==key) return pos;
  p=p->next; pos++;
 } while(p!=tail->next);
 return -1;
}

int main(){
 Node* tail=NULL;
 int ch,x,k;
 do{
  cout<<"\n1:InsFirst 2:InsLast 3:InsAfter 4:DelKey 5:Search 6:Show 0:Exit\nChoice: ";
  cin>>ch;
  switch(ch){
   case 1: cout<<"val: "; cin>>x; insertAsFirst(tail,x); break;
   case 2: cout<<"val: "; cin>>x; insertAsLast(tail,x); break;
   case 3: cout<<"after which? "; cin>>k; cout<<"val: "; cin>>x;
           if(!insertAfter(tail,k,x)) cout<<"Not found\n";
           break;
   case 4: cout<<"del val: "; cin>>k; cout<<(deleteNode(tail,k)? "Deleted\n":"Not found\n"); break;
   case 5: cout<<"search val: "; cin>>k; cout<<(search(tail,k)==-1? "Not found\n":"Found\n"); break;
   case 6: show(tail); break;
  }
 } while(ch!=0);
 return 0;
}
