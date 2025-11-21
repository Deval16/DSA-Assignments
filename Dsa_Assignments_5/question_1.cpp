
#include <iostream>
using namespace std;

struct Node{
 int val;
 Node* next;
 Node(int v){ val=v; next=NULL; }
};

void show(Node* h){
 if(!h){ cout<<"Empty\n"; return; }
 Node* p=h;
 while(p){
  cout<<p->val;
  if(p->next) cout<<" -> ";
  p=p->next;
 }
 cout<<"\n";
}

void insertBeg(Node*& h,int x){
 Node* n=new Node(x);
 n->next=h;
 h=n;
}

void insertEnd(Node*& h,int x){
 Node* n=new Node(x);
 if(!h){ h=n; return; }
 Node* p=h;
 while(p->next) p=p->next;
 p->next=n;
}

bool insertAfter(Node* h,int key,int x){
 Node* p=h;
 while(p && p->val!=key) p=p->next;
 if(!p) return false;
 Node* n=new Node(x);
 n->next=p->next;
 p->next=n;
 return true;
}

bool insertBefore(Node*& h,int key,int x){
 if(!h) return false;
 if(h->val==key){ insertBeg(h,x); return true; }
 Node* p=h;
 while(p->next && p->next->val!=key) p=p->next;
 if(!p->next) return false;
 Node* n=new Node(x);
 n->next=p->next;
 p->next=n;
 return true;
}

bool delBeg(Node*& h){
 if(!h) return false;
 Node* t=h;
 h=h->next;
 delete t;
 return true;
}

bool delEnd(Node*& h){
 if(!h) return false;
 if(!h->next){
   delete h; h=NULL; return true;
 }
 Node* p=h;
 while(p->next->next) p=p->next;
 delete p->next;
 p->next=NULL;
 return true;
}

bool delKey(Node*& h,int k){
 if(!h) return false;
 if(h->val==k) return delBeg(h);
 Node* p=h;
 while(p->next && p->next->val!=k) p=p->next;
 if(!p->next) return false;
 Node* t=p->next;
 p->next=t->next;
 delete t;
 return true;
}

int search(Node* h,int k){
 int pos=1;
 while(h){
  if(h->val==k) return pos;
  pos++; h=h->next;
 }
 return -1;
}


int main(){
 Node* head=NULL;
 int c,x,k;

 do{
  cout<<"\n1 InsertBeg 2 InsertEnd 3 InsertBefore 4 InsertAfter\n";
  cout<<"5 DelBeg 6 DelEnd 7 DelKey 8 Search 9 Show 0 Exit\n";
  cout<<"Choice: ";
  cin>>c;

  switch(c){
   case 1: cout<<"val: "; cin>>x; insertBeg(head,x); break;
   case 2: cout<<"val: "; cin>>x; insertEnd(head,x); break;
   case 3: cin>>k>>x; 
           if(!insertBefore(head,k,x)) cout<<"Not found\n";
           break;
   case 4: cin>>k>>x;
           if(!insertAfter(head,k,x)) cout<<"Not found\n";
           break;
   case 5: if(!delBeg(head)) cout<<"Empty\n"; break;
   case 6: if(!delEnd(head)) cout<<"Empty\n"; break;
   case 7: cin>>k; if(!delKey(head,k)) cout<<"Not found\n"; break;
   case 8: cin>>k; 
           int pos; pos=search(head,k);
           if(pos
