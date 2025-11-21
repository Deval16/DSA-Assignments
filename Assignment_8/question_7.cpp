#include <iostream>
using namespace std;
struct Node{ int v; Node* l; Node* r; Node(int x){v=x;l=NULL;r=NULL;} };

int findIdx(int a[],int s,int e,int val){ for(int i=s;i<=e;i++) if(a[i]==val) return i; return -1; }

Node* build(int in[], int post[], int is,int ie,int ps,int pe){
    if(is>ie || ps>pe) return NULL;
    int rootv = post[pe];
    Node* root=new Node(rootv);
    int idx = findIdx(in,is,ie,rootv);
    int leftsz = idx - is;
    root->l = build(in,post,is,idx-1, ps, ps+leftsz-1);
    root->r = build(in,post,idx+1,ie, ps+leftsz, pe-1);
    return root;
}

void pre(Node* r){ if(!r) return; cout<<r->v<<" "; pre(r->l); pre(r->r); }

int main(){
    int in[]={4,2,5,1,6,3}, post[]={4,5,2,6,3,1}, n=6;
    Node* root = build(in,post,0,n-1,0,n-1);
    pre(root); cout<<"\n";
    return 0;
}
