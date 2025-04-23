/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/
class Solution {
	//Time: O(n^3)  Space:(1)
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        //use set to store the result to make sure we don't store the same value twice
        vector<vector<int>> result;

        if(nums.size() < 4)
        {
            return result;
        }

        long long currentSum = 0;

        sort(nums.begin(), nums.end());

        int FirstIndex, i, j , k;//index we used to walk
        for(int FirstIndex = 0; FirstIndex< nums.size() - 3; ++FirstIndex)
        {
            for(int i = FirstIndex + 1; i< nums.size() - 2; ++i)
            {

                j = i + 1; 
                k = nums.size()-1;

                while(j<k)
                {
                    currentSum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[FirstIndex] - (long long)target;
                    if(currentSum > 0)
                    {
                        int usedK = k;
                        while(j<k&& nums[k] == nums[usedK])
                        {
                            --k;
                        }
                    }
                    else if(currentSum < 0)
                    {
                        
                        int usedJ = j;
                        while(j<k&& nums[j] == nums[usedJ])
                        {
                            ++j;
                        }
                    }
                    else
                    {
                        // since we sorted it, we can make sure nums[FirstIndex] <= nums[i] <= nums[j] <= nums[k]
                        // it will only store one element when we store the same set multiple times
                        result.push_back({nums[FirstIndex], nums[i] , nums[j] ,nums[k]});

                        //since we get rid of the vector set, we need to make sure the same value would not can test on twice
                        //this will always be true the first loop
                        int usedK = k;
                        int usedJ = j;
                        while(j<k&& nums[k] == nums[usedK])
                        {
                            --k;
                        }
                        while(j<k&& nums[j] == nums[usedJ])
                        {
                            ++j;
                        }
                    }
                }
                
                // skip naxt one if next num[i] is the same
                while(i+1 < nums.size()&& nums[i] == nums[i+1])
                {
                    ++i;
                }
            }
            // skip naxt one if next num[FirstIndex] is the same
            while(FirstIndex+1 < nums.size()&& nums[FirstIndex] == nums[FirstIndex+1])
            {
                ++FirstIndex;
            }
        }

        return result;
    }
};