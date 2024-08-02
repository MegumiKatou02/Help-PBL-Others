#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> v;
        int zeros = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                v.push_back(nums[i]);
            }
            else zeros++;
        }
        for(int i = 0; i < zeros; i++)
        {
            v.push_back(0);
        }
        nums = v;
    }
};

int main()
{

    return 0;
}