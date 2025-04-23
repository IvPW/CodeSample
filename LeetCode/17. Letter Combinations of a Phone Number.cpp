/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/
class Solution {
	//Time : O(N*3^N), Space:O(3^N)
public:

    void AttachString(char digit, vector<string>& result, unordered_map<char, string>& mapping)
    {
        auto& chars = mapping[digit];
        string tempString;

        if(result.empty() == true)
        {
            for(int i = 0; i < chars.length(); ++i)
            {
                tempString = "";
                tempString.append(1,chars[i]);
                result.push_back(tempString);
            }
        }
        else
        {
            vector<string> newResult;
            for(int i = 0; i < chars.length(); ++i)
            {
                tempString = "";
                tempString.append(1,chars[i]);
                for(int j =0; j < result.size(); ++j)
                {
                    newResult.push_back(result[j] + tempString);
                }
            }
            result = newResult;
        }
    }

    vector<string> letterCombinations(string digits) {
        
        unordered_map<char, string> numberMap;
        numberMap['2'] = "abc";
        numberMap['3'] = "def";
        numberMap['4'] = "ghi";
        numberMap['5'] = "jkl";
        numberMap['6'] = "mno";
        numberMap['7'] = "pqrs";
        numberMap['8'] = "tuv";
        numberMap['9'] = "wxyz";

        vector<string> result;
        for(int i = 0; i < digits.length(); ++i)
        {
            AttachString(digits[i], result, numberMap);
        }

        return result;
    }
};