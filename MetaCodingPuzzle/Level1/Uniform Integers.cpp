#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getDigitCount(long long value)
{
  if(value == 1)
  {
      //special case.  log(1) = 0, but we are looking for 1 here
      return 1;
  }
  
  return ceil(log(value) / log(10));
}

long long getBaseForDigit(int DigiCount)
{
  long long result = 1;
  
  for(int i = 0; i < DigiCount-1; ++i)
  {
    result *= 10;
    result +=1;
  }
  
  return result;
}

int getUniformCount(long long low, long long high, int DigiCount)
{
  int result = 0;
  long long base = getBaseForDigit(DigiCount);
  long long current = 0;
  
  //there are only 9 uniform avaiable
  for(int i = 1; i < 10; ++i)
  {
    current = base * i;
    if(low <= current && current <= high)
    {
      result++;
    }
  }
  
  return result;
}

int getUniformIntegerCountInInterval(long long A, long long B) {
  // Write your code here
  
  int uniformCount = 0;
  
  int DigiCountA = getDigitCount(A);
  int DigiCountB = getDigitCount(B);
  
  if(DigiCountA == DigiCountB)
  {
    return getUniformCount(A,B,DigiCountA);
  }
  
  //get the count for digicount A
  uniformCount +=getUniformCount(A,getBaseForDigit(DigiCountA) * 9, DigiCountA);
  
  //the one in middle
  uniformCount += 9* (DigiCountB - DigiCountA - 1);
  
  //get count for digicount B
  uniformCount +=getUniformCount(getBaseForDigit(DigiCountA) ,B, DigiCountB);
    
  return uniformCount;
}
