#include <iostream>
using namespace std;
const int N=6;
int M[N][N];
struct Node{
    int v; Node* next; Node(int x){v=x;next=NULL;}
 };
Node* L[N];

void addM(int u,int v)
{ M[u][v]=1; }
void addL(int u,int v)
{ Node* p=new Node(v); p->next=L[u]; L[u]=p; }
int outM(int u)
{ int c=0; for(int i=0;i<N;i++) if(M[u][i]) c++; return c; }
int inM(int u)
{ int c=0; for(int i=0;i<N;i++) if(M[i][u]) c++; return c; }
int edgesM()
{ int c=0; for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(M[i][j]) c++; return c; }

int main(){
 for(int i=0;i<N;i++) for(int j=0;j<N;j++) M[i][j]=0,L[i]=NULL;
 addM(0,1); addM(0,2); addM(2,3);
 addL(0,1); addL(0,2); addL(2,3);
 cout<<"out0="<<outM(0)<<" in0="<<inM(0)<<" edges="<<edgesM()<<"\n";
 cout<<"Adj list of 0: "; for(Node* p=L[0];p;p=p->next) cout<<p->v<<" ";
 cout<<"\n";
}
