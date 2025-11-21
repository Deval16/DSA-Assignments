// is_circular.cpp
#include <iostream>
using namespace std;
struct Node{ int v; Node* next; Node(int x){ v=x; next=NULL; } };

bool isCircular(Node* head){
 if(!head) return false;
 Node* slow=head; Node* fast=head;
 while(fast && fast->next){
  slow=slow->next;
  fast=fast->next->next;
  if(slow==fast) return true;
 }
 return false;
}

int main(){
 // test non-circular
 Node* a=new Node(1); Node* b=new Node(2); a->next=b; b->next=NULL;
 cout<<(isCircular(a)? "Circular\n":"Not Circular\n"); // Not Circular

 // make circular
 b->next=a;
 cout<<(isCircular(a)? "Circular\n":"Not Circular\n"); // Circular
 return 0;
}
