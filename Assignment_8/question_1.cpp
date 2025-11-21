
#include <iostream>
using namespace std;
struct Node{ int v; Node* l; Node* r; Node(int x){ v=x; l=NULL; r=NULL; } };

void pre(Node* t){ if(!t) return; cout<<t->v<<" "; pre(t->l); pre(t->r); }
void in(Node* t){ if(!t) return; in(t->l); cout<<t->v<<" "; in(t->r); }
void post(Node* t){ if(!t) return; post(t->l); post(t->r); cout<<t->v<<" "; }

int main(){
    Node* r=new Node(1);
    r->l=new Node(2); r->r=new Node(3);
    r->l->l=new Node(4); r->l->r=new Node(5);

    cout<<"Pre: "; pre(r); cout<<"\n";
    cout<<"In : "; in(r);  cout<<"\n";
    cout<<"Post: "; post(r); cout<<"\n";
    return 0;
}
