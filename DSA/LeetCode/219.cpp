#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, pair<int, int>> mp; // number, <index, fre>
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].second++;
            if(mp[nums[i]].second == 2)
            {
                if(abs(i - mp[nums[i]].first) <= k) return true;
                else
                {
                    mp[nums[i]].first = i;
                    mp[nums[i]].second = 1;
                }
            }
            else 
            {
                mp[nums[i]].first = i;
            }
        }
        
        return false;
    }
};