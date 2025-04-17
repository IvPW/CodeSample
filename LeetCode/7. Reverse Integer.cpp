/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

class Solution {
	//Time: O(log(N)), Space:O(1)
public:
    int reverse(int x) {


        int result = 0;

        while(x != 0)
        {
            // if the result will overflow, return 0
            if(result > INT_MAX / 10 || result < INT_MIN / 10)
            {
                return 0;
            } 

            result *= 10;
            result += x % 10;

            x = x / 10;
        }

        return result ;
        
    }
};
