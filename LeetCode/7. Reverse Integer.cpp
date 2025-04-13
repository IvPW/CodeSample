/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

class Solution {
	//Time: O(log(N)), Space:O(1)
public:
    string convert(string s, int numRows) 
    {
		//based on the number of rows, create the row as string by putting the characters in one bu one
		//append each string at the end
        if(numRows <= 1)
        {
            return s;
        }

        string result = "";

        vector<string> rows(numRows, "");

        int currentRow = 0;
        int direction = 1;
        for(int i = 0; i < s.size(); ++i)
        {
            rows[currentRow] += s[i];
            currentRow += direction;

            if((currentRow == numRows-1) || (currentRow == 0))
            {
                direction *= -1;
            }
        }

        for(int i = 0; i < numRows; ++i)
        {
            //append the rows by making each row into a string
            result+=rows[i];
        }

        return result;
    }
};