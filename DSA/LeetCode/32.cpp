#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        stack<char> st;
        int count = 0;
        int maxLength = 0;
        for(const char &x : s)
        {
            if(x == '(')
            {
               st.push(x);
            }
            else 
            {
                if(st.empty())
                {
                    continue;
                }
                else
                {
                    st.pop();
                    count += 2;
                }
            } // ))
        }
        return max(maxLength, count);
    }
};

int main()
{
    Solution s;
    cout << s.longestValidParentheses(")()())");

    return 0;
}