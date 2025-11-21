#include <iostream>
#include <stack>
using namespace std;
const int N=6; int adj[N][N], seen[N];
void dfsR(int u){
 seen[u]=1; cout<<u<<" ";
 for(int v=0;v<N;v++) if(adj[u][v] && !seen[v]) dfsR(v);
}
void dfsI(int s){
 int vis[N]={0}; stack<int> st; st.push(s);
 while(!st.empty()){
  int u=st.top(); st.pop();
  if(vis[u]) continue; vis[u]=1; cout<<u<<" ";
  for(int v=N-1;v>=0;v--) if(adj[u][v] && !vis[v]) st.push(v);
 }
}
int main(){
 for(int i=0;i<N;i++) for(int j=0;j<N;j++) adj[i][j]=0;
 adj[0][1]=adj[0][2]=adj[1][3]=adj[2][4]=1;
 for(int i=0;i<N;i++) seen[i]=0;
 cout<<"DFS rec: "; dfsR(0); cout<<"\n";
 cout<<"DFS itr: "; dfsI(0); cout<<"\n";
}
