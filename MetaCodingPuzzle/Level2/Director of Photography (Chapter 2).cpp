#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getCountInRange(vector<int>& markers, int min, int max)
{
  if(min > max)
  {
    return 0;
  }
  int count = 0;
  if(min == 0)
  {
    count = markers[max];
  }
  else
  {
    count = markers[max] - markers[min-1];
  }
  return count;
}

long long getArtisticPhotographCount(int N, string C, int X, int Y) {
  
  long long totalSet = 0;

  //init
  vector<int> P(N, 0);
  vector<int> A;
  vector<int> B(N, 0);
  int CountA = 0;
  int CountP = 0;
  int CountB = 0;
  
  // build index arrays to stpre location of A and store the count of P and B from 0~i
  for (int i = 0; i < N; ++i) 
  {
     switch (C[i])
     {
         case 'P': 
              ++CountP; 
              break;
         case 'A': 
              A.push_back(i); 
              break;
         case 'B': 
              ++CountB; 
              break;
         default:
              break;
     }
    P[i] = CountP;
    B[i] = CountB;
  }
  
  // for each A, search P and B in range of X and Y from both sides
  for (int i : A) 
  {
     //A[i] will be the index of A
     int leftMin = max(0, i - Y);
     int leftMax = i - X ;
     int rightMin = i + X;
     int rightMax = min(N-1,i + Y);
    
     int PLeft = getCountInRange(P, leftMin, leftMax);
     int PRight = getCountInRange(P, rightMin, rightMax);
     int BLeft = getCountInRange(B, leftMin, leftMax);
     int BRight = getCountInRange(B, rightMin, rightMax);
    
     totalSet += (long long)PLeft * BRight + (long long)BLeft * PRight;
    
  }
  
  
  return totalSet;
}
