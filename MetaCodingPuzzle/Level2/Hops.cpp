#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long getSecondsRequired(long long N, int F, vector<long long> P) {
  
  //the best case is when all the frogs are all in the back since we save some jumps when they are in a group.
  //in the best case, only the furthest frog need to do regular jumps. Thus, the required jump will be the distance between the furthest frog and the end.
  sort(P.begin(), P.end());

  return N - P[0];
}
