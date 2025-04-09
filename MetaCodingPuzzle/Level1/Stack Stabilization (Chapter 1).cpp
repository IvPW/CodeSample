#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getMinimumDeflatedDiscCount(int N, vector<int> R) {
  // Write your code here
  
  int deflatedDiskCount = 0;
  
  //the last one will define the size of the stack since we can't inflat them
  if(R[N-1] < N)
  {
    // not possible since the base is too small
    return -1;
  }
  
  if(N == 1)
  {
    return 0;
  }
  
  int previousDisk = R[N-1];
  
  for(int i = N-2; i>=0; --i)
  {
    if(R[i] >= previousDisk)
    {
      ++deflatedDiskCount;
      R[i] = --previousDisk;
      if(previousDisk <= 0)
      {
        return -1;
      }
    }
    else
    {
        previousDisk = R[i];
    }
  }
  
  return deflatedDiskCount;
}
