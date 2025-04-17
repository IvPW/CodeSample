/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

class Solution {
	//Time : O(logN)  Space: O(1)
public:
    int myAtoi(string s) {
        
        if(s == "")
        {
            return 0;
        }

        int index = 0;
        int sign = 1;
        int result = 0;
        int number = 0;
        //skip all whitespace
        for(; index < s.size(); ++index)
        {
            if(s[index] != ' ')
            {
                break;
            }
        }

        //get the sign
        if(s[index] == '-')
        {
            ++index;
            sign = -1;
        }
        else if(s[index] == '+')
        {
            ++index;
            sign = 1;
        }

        for(; index < s.size(); ++index)
        {
            number = (s[index] - '0');
            if(s[index] < '0' || s[index] > '9')
            {
                //not character, stop reading
                break;
            }
            //round if it is too big/small
            if(result > (INT_MAX - number) / 10.0)
            {
                return (sign == 1)?INT_MAX:INT_MIN;
            }

            result = result * 10 + number;
        }

        return result*sign;
    }
};