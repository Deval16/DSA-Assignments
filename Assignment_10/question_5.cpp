#include <iostream>
using namespace std;
const int INF=1e9;
int main(){
 int n=6;
 int w[6][6]; for(int i=0;i<n;i++) for(int j=0;j<n;j++) w[i][j]=INF;
 w[0][1]=4; w[0][2]=4; w[1][2]=2; w[1][3]=5; w[2][4]=5; w[3][4]=1; w[3][5]=3;
 int used[6]={0}; used[0]=1; int edges=0, total=0;
 while(edges<n-1){
  int a=-1,b=-1,mn=INF;
  for(int i=0;i<n;i++) if(used[i]) for(int j=0;j<n;j++) if(!used[j] && w[i][j]<mn){ mn=w[i][j]; a=i; b=j; }
  if(b==-1) break;
  cout<<a<<"-"<<b<<" w="<<mn<<"\n"; used[b]=1; total+=mn; edges++;
 }
 cout<<"Total="<<total<<"\n";
}
