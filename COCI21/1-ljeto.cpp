#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int ans[2]{},pt[8]; fill(pt,pt+8,-11);
  for(int i=0;i<n;++i){
    int t,a,b; cin>>t>>a>>b;
    ans[--a>3]+=100+(t-pt[a]<=10?50:0);
    pt[a]=t;
  }
  cout<<ans[0]<<" "<<ans[1]<<'\n';
  return 0;
}

