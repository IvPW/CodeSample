#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
  // Write your code here
  
  int pointerIndex = 1;
  long long totalTime = 0;
  
  for(int goal : C)
  {
    //get the number of seconds from pointerIndex to goal
    int distance = abs(pointerIndex - goal);
    if(distance > N/2)
    {
      distance = N - distance;
    }
    totalTime += distance;
    pointerIndex = goal;
  }
  
  
  return totalTime;
}
