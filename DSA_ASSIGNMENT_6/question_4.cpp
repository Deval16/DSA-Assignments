// dbl_palindrome.cpp
#include <iostream>
using namespace std;
struct Node{ char c; Node* prev; Node* next; Node(char ch){ c=ch; prev=NULL; next=NULL; } };

Node* build(char a[], int n){
 Node* head=NULL; Node* tail=NULL;
 for(int i=0;i<n;i++){
  Node* p=new Node(a[i]);
  if(!head) head=tail=p; else { tail->next=p; p->prev=tail; tail=p; }
 }
 return head;
}

bool isPal(Node* head){
 if(!head) return true;
 Node* tail=head;
 while(tail->next) tail=tail->next;
 while(head!=tail && head->prev!=tail){
  if(head->c!=tail->c) return false;
  head=head->next; tail=tail->prev;
 }
 return true;
}

int main(){
 char s[] = {'r','a','d','a','r'}; // change to test
 Node* head = build(s,5);
 cout<<(isPal(head)? "Palindrome\n":"Not Palindrome\n");
 return 0;
}
