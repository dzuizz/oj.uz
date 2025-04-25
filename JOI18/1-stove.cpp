#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=1e5+5;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  int t[n],s[n],res=n; for(int i=0;i<n;++i){
    cin>>t[i];
    if(i) s[i]=t[i]-t[i-1]-1;
  }
  sort(s+1,s+n);
  for(int i=1;i<=n-k;++i) res+=s[i];
  cout<<res<<'\n';
  return 0;
}

