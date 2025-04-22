/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
*/
class Solution {
	//Time: O(N), Space:O(1)
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int maxSize = 0;
        int currentSize = 0;
        while(left < right)
        {
            currentSize = min(height[left], height[right]) * (right - left);
            maxSize = max(maxSize, currentSize);

			//move the lower bar to see if we got a higher bar that allowing bigger area
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxSize;
    }
};