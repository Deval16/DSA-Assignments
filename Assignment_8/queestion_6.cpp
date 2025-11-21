#include <iostream>
using namespace std;
struct Node{ int v; Node* l; Node* r; Node(int x){v=x;l=NULL;r=NULL;} };

int findIdx(int a[],int s,int e,int val){ for(int i=s;i<=e;i++) if(a[i]==val) return i; return -1; }

Node* build(int pre[], int in[], int ps,int pe,int is,int ie){
    if(ps>pe || is>ie) return NULL;
    int rootv = pre[ps];
    Node* root=new Node(rootv);
    int idx = findIdx(in,is,ie,rootv);
    int leftsz = idx - is;
    root->l = build(pre,in, ps+1, ps+leftsz, is, idx-1);
    root->r = build(pre,in, ps+leftsz+1, pe, idx+1, ie);
    return root;
}

void inorder(Node* r){ if(!r) return; inorder(r->l); cout<<r->v<<" "; inorder(r->r); }

int main(){
    int pre[]={1,2,4,5,3,6}, in[]={4,2,5,1,6,3}, n=6;
    Node* root = build(pre,in,0,n-1,0,n-1);
    inorder(root); cout<<"\n";
    return 0;
}
