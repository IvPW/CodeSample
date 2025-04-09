#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {

  vector<pair<long long, long long>> blockedIntervals;
    
  // Sort the occupied seats to handle them in order
  sort(S.begin(), S.end());
  
  //have a marker array for N
  for(int i = 0; i < M; ++i)
  {
    //map the seats
    //S is 1-based, change it to 0-based
    long long SeatIndex = S[i]-1;
    long long SeatMinIndex = max(0LL, SeatIndex-K);
    long long SeatMaxIndex = min(SeatIndex+K, N-1);
    
    blockedIntervals.push_back({SeatMinIndex, SeatMaxIndex});
  }
  
  //merge the blocked intervals
  vector<pair<long long, long long>> mergedIntervals;
  for (auto& interval : blockedIntervals) 
  {
    if (mergedIntervals.empty() || mergedIntervals.back().second < interval.first) 
    {
        mergedIntervals.push_back(interval);
    } 
    else 
    {
        mergedIntervals.back().second = interval.second;
    }
  }
  
  long long availableSeats = 0;
  long long lastEnd = -1;

  for (auto& interval : mergedIntervals) 
  {
      // Count available seats between last end and the start of the current interval
      availableSeats += ceil(static_cast<double>(interval.first-1-lastEnd) / (K+1));
      lastEnd = interval.second;
  }
    
  // Don't forget the seats after the last blocked interval
  availableSeats += ceil(static_cast<double>(N-1-lastEnd) / (K+1));
  
    
  return availableSeats;
}
