#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> adj = {
            "", "", "abc", "def", "ghi", 
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> result;
        solve(adj, digits, 0, "", result);
        return result;
    }   
    void solve(const vector<string> &adj, const string &digits, int index, string current, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        for (const char &letter : adj[digit]) {
            solve(adj, digits, index + 1, current + letter, result);
        }
    }
};

int main()
{
    Solution s;
    vector<string> t = s.letterCombinations("299");
    for(const auto &x : t)
    {
        cout << x << " ";
    }

    return 0;
}