#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, pair<int, int>> mp;
        for(int i = 0; i < s.length(); i++)
        {
            mp[s[i]].first++;
            mp[s[i]].second = i;
        }   
        int min_idx = s.length() - 1;   
        bool check = false;
        for(const auto x : mp)
        {
            if(x.second.first == 1)
            {
                check = true;
                if(x.second.second < min_idx)
                {
                    min_idx = x.second.second;
                }
            }
        }
        if(check) return min_idx;
        return -1;
    }
};

int main()
{

    return 0;
}