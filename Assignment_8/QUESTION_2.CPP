
#include <iostream>
using namespace std;
struct Node{ int k; Node* l; Node* r; Node(int x){ k=x; l=NULL; r=NULL; } };

Node* srec(Node* r,int key){ if(!r) return NULL; if(r->k==key) return r; return key<r->k? srec(r->l,key): srec(r->r,key); }
Node* siter(Node* r,int key){ while(r){ if(r->k==key) return r; r = key<r->k? r->l: r->r; } return NULL; }

Node* findMin(Node* r){ if(!r) return NULL; while(r->l) r=r->l; return r; }
Node* findMax(Node* r){ if(!r) return NULL; while(r->r) r=r->r; return r; }

Node* inSucc(Node* root,int key){
    Node* cur = siter(root,key);
    if(!cur) return NULL;
    if(cur->r) return findMin(cur->r);
    Node* succ=NULL; Node* p=root;
    while(p){
        if(key < p->k){ succ=p; p=p->l; }
        else if(key > p->k) p=p->r;
        else break;
    }
    return succ;
}

Node* inPred(Node* root,int key){
    Node* cur = siter(root,key);
    if(!cur) return NULL;
    if(cur->l) return findMax(cur->l);
    Node* pred=NULL; Node* p=root;
    while(p){
        if(key > p->k){ pred=p; p=p->r; }
        else if(key < p->k) p=p->l;
        else break;
    }
    return pred;
}

int main(){
    Node* root=new Node(20);
    root->l=new Node(10); root->r=new Node(30);
    root->l->l=new Node(5); root->l->r=new Node(15);

    cout<<(srec(root,15)? "Found rec\n":"Not\n");
    cout<<(siter(root,17)? "Found it\n":"Not\n");
    cout<<"Min="<<findMin(root)->k<<" Max="<<findMax(root)->k<<"\n";
    Node* x=inSucc(root,15); cout<<"Succ 15 = "<<(x? x->k: -1)<<"\n";
    Node* y=inPred(root,10); cout<<"Pred 10 = "<<(y? y->k: -1)<<"\n";
    return 0;
}
