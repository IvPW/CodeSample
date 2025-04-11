/*
Given a string s, find the length of the longest substring without duplicate characters.
*/

class Solution {
	//walk over the lists to add them
	//Time: O(N), Space: O(logN)
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> subStringCharacter;
        int longestSubString = 0;
        int subStringStart = 0;

        for(int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if(subStringCharacter.find(c) == subStringCharacter.end() || subStringCharacter[c] < subStringStart)
            {
                // new character
                subStringCharacter[c] = i;
            }
            else
            {
                //if find a dupe, restart the subStringCount from the last found dupe index + 1
                //check the length of this substring and store
                //the current sub string is from subStringStart ~ i
                // update the subStringStart
                longestSubString = max(i- subStringStart, longestSubString);
                subStringStart = subStringCharacter[c] +1;
                subStringCharacter[c] = i;

            }
        }

        // calculate the last sub string
        int size = s.size();
        longestSubString = max(size- subStringStart, longestSubString);

        return longestSubString;
        
    }
};