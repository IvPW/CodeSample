/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows
*/

class Solution {
	//Time: O(N), Space:O(N)
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