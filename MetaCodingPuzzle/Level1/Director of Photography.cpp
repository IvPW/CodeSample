#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int FindValidInputForActor(const string& C, int minRange, int maxRange, char FollowUpTarget)
{
  int backdropCount = 0;
  for(int i = minRange; i <= maxRange; ++i)
  {
    if(C[i] == FollowUpTarget)
    {
      ++backdropCount;
    }
  }
  
  return backdropCount;
}

int FindValidActor(int N, const string& C, int minRange, int maxRange, int X, int Y, char FollowUpTarget)
{
  int actorCount = 0;
  
  //expect Y > X
  for(int i = minRange; i <= maxRange; ++i)
  {
    if(C[i] == 'A')
    {
      //find an actor
      actorCount += FindValidInputForActor(C, i + X, min(N,i + Y), FollowUpTarget);
    }
  }
  
  return actorCount;
}

int getArtisticPhotographCount(int N, string C, int X, int Y) {
  // Write your code here
  
  int totalSet = 0;

  for(int i = 0; i < N; ++i)
  {
    if(C[i] == 'P')
    {
      //PAB
      totalSet += FindValidActor(N, C, i + X, min(N, i + Y), X,Y, 'B');
    }
    else if(C[i] == 'B')
    {
      //BAP
      totalSet += FindValidActor(N, C, i + X, min(N, i + Y), X,Y, 'P');
    }
  }
  
  return totalSet;
}
