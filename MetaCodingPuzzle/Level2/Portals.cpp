#include <bits/stdc++.h>
#include <queue>
using namespace std;
// Write any include statements here

struct position
{
  int r;
  int c;
  
  bool operator==(const position& rhs) const
  {
    return r == rhs.r && c == rhs.c;
  }
};

int getHashIndex(int R, position value)
{
  //this is fine since the coor is 1-based
  return value.r + R * value.c;
}

//iteration
bool Iteration(const int R,const int C,const vector<vector<char>>& G, vector<vector<int>>& seconds,const multimap<char, position>& locations,  unordered_map<int, bool>&  openCloseList,list<position>& openlist,bool& foundExit, position& Exit)
{
  //if openlist is empty, we ends with no exit found
  if(openlist.empty())
  {
    foundExit = false;
    return true;
  }
  
  //pop the first element in openlist, add the nearby that is not in closelist into open list
  position currentPosition = *openlist.begin();
  openCloseList[getHashIndex(R,currentPosition)] = false;
  openlist.pop_front();
  
  //check if this is the exit
  {
    auto exitPositions= locations.equal_range('E');
    for (auto it=exitPositions.first; it!=exitPositions.second; ++it)
    {
      if(it->second == currentPosition)
      {
        //found it
        foundExit = true;
        Exit = currentPosition;
        return true;
      }
    }
  }
  
  int baseSeconds = seconds[currentPosition.r][currentPosition.c];
  
  position tempPos;
  int tempId;
  //get up
  tempPos = {currentPosition.r - 1, currentPosition.c};
  tempId = getHashIndex(R,tempPos);
  if(tempPos.r >=0 &&G[tempPos.r][tempPos.c] != '#'&& openCloseList.find(tempId) == openCloseList.end())
  {
    openlist.push_back(tempPos);
    openCloseList[tempId] = true;
    seconds[tempPos.r][tempPos.c] = min(baseSeconds + 1, seconds[tempPos.r][tempPos.c]);
  }
  //get down
  tempPos = {currentPosition.r + 1, currentPosition.c};
  tempId = getHashIndex(R,tempPos);
  if(tempPos.r < R && G[tempPos.r][tempPos.c] != '#'&&  openCloseList.find(tempId) == openCloseList.end())
  {
    openlist.push_back(tempPos);
    openCloseList[tempId] = true;
    seconds[tempPos.r][tempPos.c] = min(baseSeconds + 1, seconds[tempPos.r][tempPos.c]);
  }
  //get right
  tempPos = {currentPosition.r, currentPosition.c + 1};
  tempId = getHashIndex(R,tempPos);
  if(tempPos.c < C && G[tempPos.r][tempPos.c] != '#'&&  openCloseList.find(tempId) == openCloseList.end())
  {
    openlist.push_back(tempPos);
    openCloseList[tempId] = true;
    seconds[tempPos.r][tempPos.c] = min(baseSeconds + 1, seconds[tempPos.r][tempPos.c]);
  }
  //get left
  tempPos = {currentPosition.r , currentPosition.c - 1};
  tempId = getHashIndex(R,tempPos);
  if(tempPos.c >=0 && G[tempPos.r][tempPos.c] != '#'&&  openCloseList.find(tempId) == openCloseList.end())
  {
    openlist.push_back(tempPos);
    openCloseList[tempId] = true;
    seconds[tempPos.r][tempPos.c] = min(baseSeconds + 1, seconds[tempPos.r][tempPos.c]);
  }
  //get portals
  if(G[currentPosition.r][currentPosition.c] >= 'a' && G[currentPosition.r][currentPosition.c] <= 'z')
  {
    //this is on a protal
    auto protalPositions= locations.equal_range(G[currentPosition.r][currentPosition.c]);
    for (auto it=protalPositions.first; it!=protalPositions.second; ++it)
    {
      
      //add them into open list if not in closelist already
      if(openCloseList.find(getHashIndex(R,it->second)) == openCloseList.end())
      {
        openlist.push_back(it->second);
        openCloseList[getHashIndex(R,it->second)] = true;
        seconds[it->second.r][it->second.c] = min(baseSeconds + 1, seconds[it->second.r][it->second.c]);
      }
    }
  }
  return false;
}

int getSecondsRequired(int R, int C, vector<vector<char>> G) {
  // Write your code here
  
  multimap<char, position> locationList; 
  position startingPosition;
  vector<vector<int>> seconds(R);

  //first pass to find all teleportors and the starting position
  for(int i = 0; i < R; ++i)
  {
    seconds[i].resize(C);
    for(int j = 0; j < C; ++j)
    {
      seconds[i][j] = numeric_limits<int>::max();
      if(G[i][j] == 'E' || (G[i][j] >= 'a' && G[i][j] <= 'z'))
      {
        //a protal or exit
        locationList.insert({G[i][j], {i,j}});
      }
      else if(G[i][j] == 'S')
      {
        //starting position
        startingPosition = {i,j};
        seconds[i][j] = 0;
      }
    }
  }
  
  //if not in the map, it is yet to been looked at, if true, it is in open list, false if in close list
  unordered_map<int, bool> openCloseList;
  list<position> openList;
    
  //first node
  openList.push_back(startingPosition);
  openCloseList[getHashIndex(R,startingPosition)]  = true;
  
  bool searchEnd = false;
  bool foundExit = false;
  position Exit;
  do
  {
    searchEnd = Iteration(R,C,G,seconds, locationList,openCloseList, openList,foundExit, Exit);
  }while(!searchEnd);
  
  if(!foundExit)
  {
    return -1;
  }
  
  return seconds[Exit.r][Exit.c];
}
