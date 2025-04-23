//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
class Solution {
    //time: O(4^N/sqrt(N)) Space: O(4N /sqrt(N))
    vector<string> result;

    void addParenthesis(int open, int close, int n, string input)
    {
        if(open + close == n*2)
        {
            result.push_back(input);
            return;
        }

        //either add an open"(" or a close")" when it make sense
        if(open < n)
        {
            addParenthesis(open + 1, close, n, input + "(");
        }
        if(open > close)
        {
            addParenthesis(open, close+1, n, input + ")");
        }
    }
public:
    vector<string> generateParenthesis(int n) 
    {
        result.clear();
        addParenthesis(0,0,n, "");
        return result;
    }
};
