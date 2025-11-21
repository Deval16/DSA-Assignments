#include <iostream>
#include <queue>
using namespace std;
const int N=6; int adj[N][N], vis[N];
void bfs(int s){
 for(int i=0;i<N;i++) vis[i]=0;
 queue<int> q; vis[s]=1; q.push(s);
 while(!q.empty()){
  int u=q.front(); q.pop(); cout<<u<<" ";
  for(int v=0;v<N;v++) if(adj[u][v] && !vis[v]){ vis[v]=1; q.push(v); }
 }
}
int main(){
 for(int i=0;i<N;i++) for(int j=0;j<N;j++) adj[i][j]=0;
 adj[0][1]=adj[0][2]=adj[1][3]=adj[2][4]=1;
 cout<<"BFS: "; bfs(0); cout<<"\n";
}
