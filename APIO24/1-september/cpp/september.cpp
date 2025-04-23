#include "september.h"
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=1e5+5;
vector<vector<int>> adj;
int maxi[5][MAXN],_ptr;
int solve(int N,int M,vector<int> F,vector<vector<int>> S) {
  for(int i=0;i<M;++i){
    maxi[i][0]=0;
    for(int j=0;j<N-1;++j)
      maxi[i][S[i][j]]=j;
    for(int j=N-1;j>0;--j)
      maxi[i][F[j]]=max(maxi[i][F[j]],maxi[i][j]);
  }

  int c[N]; memset(c,0,sizeof c);
  int ans=0,cnt=0;
  for(int i=0;i<N-1;){
    int nx=0;
    for(int j=0;j<M;++j){
      int x=S[j][i],k=maxi[j][x];
      if(c[x]==0) ++cnt;
      if(++c[x]==M) --cnt;
      nx=max(nx,k);
    }
    while(i++<nx){
      for(int j=0;j<M;++j){
        int x=S[j][i],k=maxi[j][x];
        if(c[x]==0) ++cnt;
        if(++c[x]==M) --cnt;
        nx=max(nx,k);
      }
    }
    if(cnt==0) ++ans;
  }
  return ans;
}

