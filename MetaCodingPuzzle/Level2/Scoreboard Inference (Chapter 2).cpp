#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getMinProblemCount(int N, vector<int> S) {
  // Write your code here
  
  //find the max score
  sort(S.begin(), S.end());
  
  int maxScore = S[N-1];
  int minQuestion = maxScore / 3; //min possible
  vector<int> hasCount = {0,0,0};
  bool has1 = false;
  
  if(N == 1)
  {
    return maxScore/3 + 1;
  }
  
  
  for(int i = 0; i < N; ++i)
  {
    if(S[i] == 1)
     {
       has1 = true;
     }
    if(hasCount[S[i] % 3] == 0)
    {
      hasCount[S[i] % 3] = 1;
    }
  }
  
  //step 1 the min question:  max/3 + question that needs 1 and 2
  
  minQuestion += hasCount[1] + hasCount[2];
    
  //step 2: if max is already multiple of 3, remove 1 question when we have 1 and 2
  if(maxScore%3 == 0 && hasCount[1] == 1 && hasCount[2] == 1)
  {
    minQuestion--;
  }
  
  //step 3: if max is 3N+1 and we know that we don't need 1 here, remove the 1
  if(maxScore%3 == 1 && maxScore - S[N-2] != 1 && !has1 && hasCount[2] == 1)
  {
     minQuestion--;
  }
  
  return minQuestion;
}
