
#include <iostream>
#include <stack>
using namespace std;
struct Node{ int v; Node* l; Node* r; Node(int x){v=x;l=NULL;r=NULL;} };

void inorder(Node* root){
    stack<Node*> st;
    Node* cur=root;
    while(cur || !st.empty()){
        while(cur){ st.push(cur); cur=cur->l; }
        cur=st.top(); st.pop();
        cout<<cur->v<<" ";
        cur=cur->r;
    }
}

int main(){
    Node* r=new Node(4);
    r->l=new Node(2); r->r=new Node(6);
    r->l->l=new Node(1); r->l->r=new Node(3);
    inorder(r); cout<<"\n";
    return 0;
}
