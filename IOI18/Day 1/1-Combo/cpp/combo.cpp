#include "combo.h"

std::string guess_sequence(int N){
  std::string p="",s="";
  p=press("AB")?press("A")?"A":"B":press("X")?"X":"Y";
  for(auto&c:"ABXY") if(c!=p[0]) s+=c;
  for(int i=1,k;i<N-1;++i){
    k=press(p+s[0]+s[0]+p+s[0]+s[1]+p+s[0]+s[2]+p+s[1]);
    if(k==i) p+=s[2];
    else if(k==i+1) p+=s[1];
    else p+=s[0];
  }

  if(N>1){
    if(press(p+s[0])==N) p+=s[0];
    else if(press(p+s[1])==N) p+=s[1];
    else p+=s[2];
  }
  return p;
}

