/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/
class Solution {
	//Time: O(n^2)  Space:(1)
public:
    int threeSumClosest(vector<int>& nums, int target) {


        int currentSum = 0;
        int smallestDiff = INT_MAX;
        int closetTarget = 0;
        sort(nums.begin(), nums.end());

        int j,k; //index we used to walk
        
        for(int i = 0; i< nums.size() - 2; ++i)
        {
            j = i + 1; 
            k = nums.size()-1;

            while(j<k)
            {
                currentSum = nums[i] + nums[j] + nums[k];
                if(smallestDiff > abs(currentSum - target))
                {
                    closetTarget = currentSum;
                    smallestDiff = abs(currentSum - target);
                    if(smallestDiff == 0)
                    {
                        break;
                    }
                }

                if(currentSum > target)
                {
                    --k;
                }
                else if(currentSum < target)
                {
                    ++j;
                }
                else
                {
                    --k;
                    ++j;
                }
            }
        }


        return closetTarget;
    }
};