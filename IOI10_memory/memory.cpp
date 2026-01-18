#include "grader.h"
#include "memory.h"

void play(){
  int a[25]{},b[25]{};
  for(int i=1;i<=50;++i){
    char c=faceup(i);
    int j=c-'A';
    (a[j]?b:a)[j]=i;
  }
  for(int i=0;i<25;++i){
    faceup(a[i]);
    faceup(b[i]);
  }
}
