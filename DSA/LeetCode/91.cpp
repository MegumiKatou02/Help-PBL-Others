#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int numDecodings(string s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0;
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        int num1 = stoi(s.substr(i - 1, 1));
        int num2 = stoi(s.substr(i - 2, 2));
        // cout << num1 << " " << num2 << "\n";
        
        if (num1 >= 1 && num1 <= 9) {
            dp[i] += dp[i - 1];
        }
        
        if (num2 >= 10 && num2 <= 26) {
            dp[i] += dp[i - 2];
        }
        // cout << dp[i] << ":\n";
    }
    
    return dp[n];
}
    
};

int main()
{
    Solution s;
    cout << s.numDecodings("12106");
    return 0;
}