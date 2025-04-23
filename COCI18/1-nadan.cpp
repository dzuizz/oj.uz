#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int k,n; cin>>k>>n;
  for(int i=1;i<n;++i) cout<<i<<'\n';
  cout<<k-n*(n-1)/2<<'\n';
  return 0;
}

