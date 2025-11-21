#include <iostream>
using namespace std;
const int INF=1e9;
int main(){
 int n=6, src=0;
 int w[6][6]; for(int i=0;i<n;i++) for(int j=0;j<n;j++) w[i][j]=INF;
 w[0][1]=7; w[0][2]=9; w[0][5]=14; w[1][2]=10; w[1][3]=15; w[2][3]=11; w[2][5]=2; w[3][4]=6; w[4][5]=9;
 int dist[6], vis[6]={0};
 for(int i=0;i<n;i++) dist[i]=INF; dist[src]=0;
 for(int it=0;it<n;it++){
  int u=-1, best=INF;
  for(int i=0;i<n;i++) if(!vis[i] && dist[i]<best){ best=dist[i]; u=i; }
  if(u==-1) break;
  vis[u]=1;
  for(int v=0;v<n;v++) if(w[u][v]<INF && !vis[v]) if(dist[u]+w[u][v]<dist[v]) dist[v]=dist[u]+w[u][v];
 }
 cout<<"dist from "<<src<<":\n";
 for(int i=0;i<n;i++) cout<<i<<":"<<(dist[i]==INF?-1:dist[i])<<"\n";
}
