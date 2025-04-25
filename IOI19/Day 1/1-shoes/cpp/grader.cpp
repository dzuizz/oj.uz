#include "shoes.h"
#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5;
int fw[N],i,n,ret,x;
long long ans;
unordered_map<int,priority_queue<int>> mp;
void upd(int i){ for(;i<N;i+=i&-i) ++fw[i]; }
int sum(int i){
  int ret=0;
  for(;i>0;i-=i&-i) ret+=fw[i];
  return ret;
}
int sum(int l,int r){ return sum(r)-sum(l-1); }
long long count_swaps(vector<int> s){
  int n=s.size();
  for(int i=0;i<n;++i) mp[s[i]].emplace(-i);
  for(int i=0;i<n;++i){
    if(sum(i,i)) continue;
    int x=-mp[-s[i]].top();
    upd(x);
    ans+=(--x-i)-sum(i+1,x)+(s[i]>0);
    mp[s[i]].pop(); mp[-s[i]].pop();
  }
  return ans;
}

