#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vt;
        map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);
        }
        vector<string> x;
        for(pair<string, vector<string>> p : mp)
        {
            vt.push_back(p.second);
        }
        return vt;
    }
};

int main()
{
    Solution s;
    vector<string> t = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> h = s.groupAnagrams(t);
    for(auto a : h)
    {
        for(auto b : a)
        {
            cout << b << " ";
        }
        cout << "\n";
    }
    return 0;
}