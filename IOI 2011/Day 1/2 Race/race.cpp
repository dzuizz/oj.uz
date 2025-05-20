#include "race.h"
#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5;
int K,ans=INT_MAX,di[N],de[N];
vector<pair<int,int>> g[N];
void dfs_init(int i,int p){
  for(auto&[w,j]:g[i]) if(j!=p){
    di[j]=di[i]+w;
    de[j]=de[i]+1;
    dfs_init(j,i);
  }
}
map<int,int> f(int i,int p){
  map<int,int> mp;
  mp[di[i]]=de[i];
  for(auto&[_,j]:g[i]) if(j!=p){
    map<int,int> nmp=f(j,i);
    if(mp.size()<nmp.size()) swap(mp,nmp);
    for(auto&[w,d]:nmp) if(mp.find(K+2*di[i]-w)!=mp.end())
      ans=min(ans,mp[K+2*di[i]-w]+d-2*de[i]);
    for(auto&[w,d]:nmp){
      if(mp.find(w)==mp.end()) mp[w]=d;
      else mp[w]=min(mp[w],d);
    }
  }
  return mp;
}

int best_path(int n, int k, int H[][2], int L[]){
  K=k;
  for(int i=0;i<n-1;++i){
    g[H[i][0]].emplace_back(L[i],H[i][1]);
    g[H[i][1]].emplace_back(L[i],H[i][0]);
  }
  dfs_init(0,-1);
  map<int,int> mp=f(0,-1);
  return ans==INT_MAX?-1:ans;
}

