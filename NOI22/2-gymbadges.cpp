#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=500000;
int x[N],l[N],ord[N];
priority_queue<int> pq;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  for(int i=0;i<n;++i) cin>>x[i];
  for(int i=0;i<n;++i) cin>>l[i];
  iota(ord,ord+n,0);
  sort(ord,ord+n,[&](const int&a,const int&b){
    return x[a]+l[a]<x[b]+l[b];
  });
  for(int i=0,r=0;i<n;++i){
    if(r<=l[ord[i]]){
      r+=x[ord[i]];
      pq.emplace(x[ord[i]]);
    }else if(pq.size()&&pq.top()>x[ord[i]]){
      r+=x[ord[i]]-pq.top();
      pq.pop(); pq.emplace(x[ord[i]]);
    }
  }
  cout<<pq.size()<<'\n';
  return 0;
}

