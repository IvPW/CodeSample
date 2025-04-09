#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getMinProblemCount(int N, vector<int> S) {
  // Write your code here
  
  //find the max score
  sort(S.begin(), S.end());
  
  //the min will be either max of S devide by 2 or +1 of that depends on if there is any odd number
  int maxScore = S[N-1];
  if(maxScore % 2 != 0)
  {
    return (maxScore / 2) + 1;
  }
  
  for(int i = 0; i < N; ++i)
  {
    if(S[i] % 2 != 0)
    {
      return (maxScore / 2) + 1;
    }
  }
  
  return maxScore / 2;
}
