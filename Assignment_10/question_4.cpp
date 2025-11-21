#include <iostream>
#include <algorithm>
using namespace std;
struct E{ int u,v,w; };
int p[10];
int findp(int x){ return p[x]==x?x:p[x]=findp(p[x]); }
void uni(int a,int b){ a=findp(a); b=findp(b); if(a!=b) p[b]=a; }

int main(){
 E es[]={ {0,1,4},{0,2,4},{1,2,2},{1,3,5},{2,4,5},{3,4,1},{3,5,3} };
 int m = sizeof(es)/sizeof(es[0]), n=6;
 sort(es, es+m, [](const E&a,const E&b){ return a.w<b.w; });
 for(int i=0;i<n;i++) p[i]=i;
 int cnt=0, tot=0;
 for(int i=0;i<m && cnt<n-1;i++){
  if(findp(es[i].u)!=findp(es[i].v)){ uni(es[i].u,es[i].v); cout<<es[i].u<<"-"<<es[i].v<<" w="<<es[i].w<<"\n"; tot+=es[i].w; cnt++; }
 }
 cout<<"Total="<<tot<<"\n";
}
