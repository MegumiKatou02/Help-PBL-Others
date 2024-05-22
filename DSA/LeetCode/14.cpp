#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";
        if (n == 1) return strs[0];

        string prefix = strs[0];
        int prefixLength = prefix.length();

        for (int i = 1; i < n; i++) {
            int compareLength = min(prefixLength, static_cast<int>(strs[i].length()));
            
            int j = 0;
            while (j < compareLength && prefix[j] == strs[i][j]) {
                j++;
            }

            prefixLength = j;
        }

        return prefix.substr(0, prefixLength);
    }
};

int main()
{
    Solution s;
    vector<string> m = {"flower","flow","flight"};
    cout << s.longestCommonPrefix(m);

    return 0;
}