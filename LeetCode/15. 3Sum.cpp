/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/
class Solution {
	//Time: O(n^2)  Space:(N)
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        //use set to store the result to make sure we don't store the same value twice
        set<vector<int>> resultSet;
        vector<vector<int>> result;

        int currentSum = 0;

        sort(nums.begin(), nums.end());

        int j,k; //index we used to walk
        
        for(int i = 0; i< nums.size() - 2; ++i)
        {
            j = i + 1; 
            k = nums.size()-1;

            while(j<k)
            {
                currentSum = nums[i] + nums[j] + nums[k];

                if(currentSum > 0)
                {
                    --k;
                }
                else if(currentSum < 0)
                {
                    ++j;
                }
                else
                {
                    // since we sorted it, we can make sure nums[i] <= nums[j] <= nums[k]
                    // it will only store one element when we store the same set multiple times
                    resultSet.insert({nums[i] , nums[j] ,nums[k]});
                    --k;
                    ++j;
                    
                }
            }
        }

        for(auto element : resultSet)
        {
            result.push_back(element);
        }

        return result;
    }
};