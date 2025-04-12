/*
Given a string s, return the longest palindromic substring in s.
*/

class Solution {
	// Time: O(N^2), Space: O(1)
public:

 bool check(string& s, int i, int j) {
        int left = i;
        int right = j - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    string longestPalindrome(string s) {

        //check all the character with half way to the end
        //stop when you have something that is longer than everything you could find

        for(int i = s.size(); i > 0; --i)
        {
            // is there a palindromic string from s[i]?
            // started with longest
            for(int j = 0; j <= s.size() - i; ++j)
            {
                if(check(s, j, j + i))
                {
                    return s.substr(j, i);
                }
            }
        }
        return "";
    }
};