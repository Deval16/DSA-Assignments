
#include <iostream>
#include <climits>
using namespace std;
struct Node{ int v; Node* l; Node* r; Node(int x){v=x;l=NULL;r=NULL;} };

bool ok(Node* t,int lo,int hi){
    if(!t) return true;
    if(t->v<lo || t->v>hi) return false;
    return ok(t->l,lo,t->v-1) && ok(t->r,t->v+1,hi);
}

int main(){
    Node* r=new Node(10);
    r->l=new Node(5); r->r=new Node(20);
    cout<<(ok(r,INT_MIN,INT_MAX)? "Is BST\n":"Not BST\n");
    r->r->l=new Node(8); // breaks BST
    cout<<(ok(r,INT_MIN,INT_MAX)? "Is BST\n":"Not BST\n");
    return 0;
}
