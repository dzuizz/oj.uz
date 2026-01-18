#include "reverse.h"

std::vector<long long> reverse(std::vector<long long> a) {
  int n=a.size();
  for(int i=0;i<n/2;++i) std::swap(a[i],a[n-i-1]);
	return a;
}

