#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int b[n]; for(auto&x:b) cin>>x;
  int run=0;
  for(int i=0;i<n;++i){
    int x=b[i]*(i+1)-run;
    cout<<x<<" ";
    run+=x;
  }
  cout<<'\n';
  return 0;
}

