
#include <iostream>
using namespace std;
struct Node{ int k; Node* l; Node* r; Node(int x){k=x;l=NULL;r=NULL;} };

Node* insert(Node* r,int key){
    if(!r) return new Node(key);
    if(key<r->k) r->l = insert(r->l,key);
    else if(key>r->k) r->r = insert(r->r,key); // ignore equals
    return r;
}
Node* findMin(Node* r){ while(r && r->l) r=r->l; return r; }

Node* del(Node* r,int key){
    if(!r) return NULL;
    if(key<r->k) r->l = del(r->l,key);
    else if(key>r->k) r->r = del(r->r,key);
    else {
        if(!r->l && !r->r){ delete r; return NULL; }
        else if(!r->l){ Node* t=r->r; delete r; return t; }
        else if(!r->r){ Node* t=r->l; delete r; return t; }
        else{
            Node* s=findMin(r->r);
            r->k = s->k;
            r->r = del(r->r, s->k);
        }
    }
    return r;
}

int maxD(Node* r){ if(!r) return 0; int a=maxD(r->l), b=maxD(r->r); return 1 + (a>b? a:b); }
int minD(Node* r){ if(!r) return r? ( (!r->l && !r->r)?1 : (r->l? 1+minD(r->l) : 1+minD(r->r)) ):0; }

int main(){
    Node* root=NULL;
    int a[]={20,10,5,15,30,25,40};
    for(int i=0;i<7;i++) root=insert(root,a[i]);
    cout<<"maxD="<<maxD(root)<<" minD="<<minD(root)<<"\n";
    root = del(root,10);
    cout<<"deleted 10\n";
    cout<<"maxD now="<<maxD(root)<<"\n";
    return 0;
}
