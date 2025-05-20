#include "cave.h"
#include <bits/stdc++.h>
using namespace std;
void exploreCave(int N) {
  int S[N],D[N];
  memset(D,-1,sizeof D);
  for(int i=0;i<N;++i){
    for(int j=0;j<N;++j) if(D[j]==-1) S[j]=0;
    int q=tryCombination(S);
    bool k=(q==-1||q>i);
    int l=0,r=N-1,m,ans;
    while(l<=r){
      m=(l+r)>>1;
      for(int j=0;j<N;++j) if(D[j]==-1)
        S[j]=(m<=j&&j<=r?k^1:k);
      int q=tryCombination(S);
      if(q==-1||q>i) ans=m,l=m+1;
      else r=m-1;
    }
    S[ans]=k^1,D[ans]=i;
  }
  answer(S,D);
}

