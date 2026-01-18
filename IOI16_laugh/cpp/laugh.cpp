#include "laugh.h"

int longest_laugh(std::string s)
{
  int n=s.size(),res=0,cur=0;
  for(int i=0;i<n;++i){
    if(s[i]=='h'||s[i]=='a'){
      if(!cur) ++cur;
      else if((s[i-1]=='h'||s[i-1]=='a')&&s[i]!=s[i-1]) ++cur;
      else cur=1;
    }else cur=0;
    res=std::max(res,cur);
  }
  return res;
}
