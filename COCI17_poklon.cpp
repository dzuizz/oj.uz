#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
  int l,r,m,v;
  node *lf,*rg;
  node(int _l,int _r): l(_l),r(_r),m((_l+_r)>>1),v(0) {
    if(l!=r)
      lf=new node(l,m),
      rg=new node(m+1,r);
  }
  void upd(int x,int _v){
    if(l==r){ v=_v; return; }
    if(x<=m) lf->upd(x,_v);
    else rg->upd(x,_v);
    v=lf->v+rg->v; 
  }
  int qry(int x,int y){
    //cout<<l<<" "<<r<<": "<<v<<'\n';
    if(r<x||l>y) return 0;
    if(x<=l&&r<=y) return v;
    return lf->qry(x,y)+rg->qry(x,y);
  }
}*root;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,q; cin>>n>>q;
  int a[n],ta[n];
  for(int i=0;i<n;++i){
    cin>>a[i];
    ta[i]=a[i];
  }
  sort(ta,ta+n);
  for(int i=0,m=unique(ta,ta+n)-ta;i<n;++i)
    a[i]=lower_bound(ta,ta+m,a[i])-ta;
  int nx[n],occ[n];
  memset(nx,-1,sizeof nx);
  memset(occ,-1,sizeof occ);
  for(int i=0;i<n;++i){
    if(occ[a[i]]!=-1) nx[occ[a[i]]]=i;
    occ[a[i]]=i;
  }
  root=new node(0,n-1);
  bool vi[n]; memset(vi,0,sizeof vi);
  for(int i=0;i<n;++i){
    if(vi[a[i]]) continue;
    vi[a[i]]=1;
    if(nx[i]!=-1){
      root->upd(nx[i],1);
      if(nx[nx[i]]!=-1) root->upd(nx[nx[i]],-1);
    }
  }
  //for(int i=0;i<n;++i) cout<<root->qry(i,i)<<" "; cout<<'\n';
  pair<pair<int,int>,int> qrys[q];
  for(int i=0;i<q;++i){
    cin>>qrys[i].first.first>>qrys[i].first.second;
    qrys[i].second=i;
  }
  sort(qrys,qrys+q);
  int ans[q];
  for(int i=0,pl=0;i<q;++i){
    auto[l,r]=qrys[i].first; --l,--r;
    while(pl<l){
      if(nx[pl]!=-1){
        root->upd(nx[pl],0);
        if(nx[nx[pl]]!=-1){
          root->upd(nx[nx[pl]],1);
          if(nx[nx[nx[pl]]]!=-1)
            root->upd(nx[nx[nx[pl]]],-1);
        }
      }
      ++pl;
    }
    ans[qrys[i].second]=root->qry(l,r);
  }
  for(auto&x:ans) cout<<x<<'\n';
  return 0;
}

