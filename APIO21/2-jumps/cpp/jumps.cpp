#include "jumps.h"
#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5,L=18;
int H[N];
int lf[N][L],rg[N][L],st[N][L],p[N][L];
int n;
void init(int _n,vector<int> _H) {
  n=_n;
  for(int i=0;i<n;++i) H[i]=_H[i];

  for(int i=0;i<n;++i) st[i][0]=i;
  for(int j=0;j<L-1;++j) for(int i=0;i+(1<<(j+1))<=n;++i){
    int a=i,b=i+(1<<j);
    if(H[st[a][j]]>H[st[b][j]]) st[i][j+1]=st[a][j];
    else st[i][j+1]=st[b][j];
  }

  stack<int> s;
  for(int i=0;i<n;++i){
    while(s.size()&&H[s.top()]<=H[i]) s.pop();
    if(s.size()) lf[i][0]=s.top();
    else lf[i][0]=i;
    s.emplace(i);
  }
  while(s.size()) s.pop();
  for(int i=n-1;i>=0;--i){
    while(s.size()&&H[s.top()]<=H[i]) s.pop();
    if(s.size()) rg[i][0]=s.top();
    else rg[i][0]=i;
    s.emplace(i);
  }
  for(int i=0;i<n;++i)
    p[i][0]=H[lf[i][0]]>H[rg[i][0]]?lf[i][0]:rg[i][0];

  for(int j=0;j<L-1;++j) for(int i=0;i<n;++i)
    p[i][j+1]=p[p[i][j]][j],
    lf[i][j+1]=lf[lf[i][j]][j],
    rg[i][j+1]=rg[rg[i][j]][j];
}

int get_min(int l,int r){
  int k=log2(r-l+1);
  return H[st[l][k]]<H[st[r-(1<<k)+1][k]]?st[l][k]:st[r-(1<<k)+1][k];
}

int minimum_jumps(int A,int B,int C,int D){
  int t=C;
  for(int j=L-1;j>=0;--j) if(rg[t][j]<=D)
    t=rg[t][j];

  int s=B;
  for(int j=L-1;j>=0;--j) if(lf[s][j]>=A&&H[lf[s][j]]<H[t])
    s=lf[s][j];

  int x=-1;
  if(B<C-1){
    x=B+1;
    for(int j=L-1;j>=0;--j) if(rg[x][j]<C)
      x=rg[x][j];
    x=H[x];
  }
  //cerr<<s<<" "<<x<<" "<<t<<'\n';
  if(H[s]>=H[t]||x>=H[t]) return -1;

  if(H[s]>=x) return 1;

  int ans=0;
  for(int j=L-1;j>=0;--j) if(H[p[s][j]]<x)
    ans+=1<<j,s=p[s][j];
  if(H[rg[s][0]]==x) return ans+2;
  else if(H[p[s][0]]<H[t]) return ans+2;

  //for(int j=0;j<L;++j) cerr<<rg[s][j]<<" "; cerr<<'\n';
  for(int j=L-1;j>=0;--j) if(rg[s][j]<C)
    ans+=1<<j,s=rg[s][j];
  //cerr<<ans<<" "<<s<<'\n';
  return ++ans;
}

int f(int i,int x,int y){
  if(x<=i&&i<=y) return 0;
  int ret=2e9;
  if(lf[i][0]!=i) ret=min(ret,f(lf[i][0],x,y)+1);
  if(rg[i][0]!=i) ret=min(ret,f(rg[i][0],x,y)+1);
  return ret;
}
int brute_force(int A,int B,int C,int D){
  int ret=2e9;
  for(int i=A;i<=B;++i)
    ret=min(ret,f(i,C,D));
  return ret==2e9?-1:ret;
}

