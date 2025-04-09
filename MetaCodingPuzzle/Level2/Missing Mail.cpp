#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

double getMaxExpectedProfit(int N, vector<int> V, int C, double S) {
    
  
  if(S == 0)
  {
    double expectedValue = 0;
    for(int value : V)
    {
      expectedValue += value;
    }
    
    return expectedValue -C;
  }
  
  //element 0 is 0, meaning we haven't pick up anything
  //for each element i, it present the best expected value for picking up on that day
  vector<double> expectedValues(N+1);
  
  double oddOfPackage = 1-S;
  double sum = 0;
  
  //start as 1 so we can calculate all the cases before + the case we never pick anything up
  for(int i = 1 ; i <= N; ++i)
  {
    sum = 0;
    double odds = 1;
    //going reverse so the older package got the odd^daysStay
    for(int j = i-1; j >= 0; --j)
    {
      sum += V[j] * odds;
      odds *= oddOfPackage;
      expectedValues[i] = max(expectedValues[i], expectedValues[j] + sum);
    }
    expectedValues[i] -= C;
  }
  
  
  return *max_element(expectedValues.begin(), expectedValues.end());
}
