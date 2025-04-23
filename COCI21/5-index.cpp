#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
constexpr int N=200005,Q=200005,S=447;
pair<pair<int,int>,int> qry[Q];
int fw[N],p[N],v[Q];
int maxp,n,q,l,r=-1,lf,rg,mid;
int sum(int i){
  int ret=0;
  for(;i>0;i-=i&-i) ret+=fw[i];
  return ret;
}
#define sum(l,r) sum(r)-sum(l-1)
void add(int i,int v){ for(;i<=maxp;i+=i&-i) fw[i]+=v; }
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>n>>q;
  for(int i=0;i<n;++i) cin>>p[i],maxp=max(maxp,p[i]);
  for(int i=0;i<q;++i) cin>>qry[i].f.f>>qry[i].f.s,--qry[i].f.f,--qry[i].f.s,qry[i].s=i;
  sort(qry,qry+q,[&](const pair<pair<int,int>,int>&a,const pair<pair<int,int>,int>&b){ return a.f.f/S==b.f.f/S?(a.f.f/S)&1?a.f.s>b.f.s:a.f.s<b.f.s:a.f.f<b.f.f; });
  for(int i=0;i<q;++i){
    auto&[lr,j]=qry[i];
    auto&[nl,nr]=lr;
    while(l>nl) add(p[--l],1);
    while(r<nr) add(p[++r],1);
    while(l<nl) add(p[l++],-1);
    while(r>nr) add(p[r--],-1);
    lf=1,rg=maxp;
    while(lf<=rg){
      mid=(lf+rg)>>1;
      if(sum(mid,maxp)>=mid) v[j]=mid,lf=mid+1;
      else rg=mid-1;
    }
  }
  for(int i=0;i<q;++i) cout<<v[i]<<'\n';
  return 0;
}

