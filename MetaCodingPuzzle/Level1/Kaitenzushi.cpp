#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getMaximumEatenDishCount(int N, vector<int> D, int K) {
  // Write your code here
  
  unordered_set<int> takenDishes;
  queue<int> dishQueue;
  int dishesConsume = 0;
  
  for(int dish : D)
  {
    if(takenDishes.find(dish) == takenDishes.end())
    {
      if(takenDishes.size() == K)
      {
        takenDishes.erase(dishQueue.front());
        dishQueue.pop();
      }
      
      //we are interested in this dish
      takenDishes.insert(dish);
      dishQueue.push(dish);
      
      ++dishesConsume;
      
    }
  }
  
  return dishesConsume;
}
