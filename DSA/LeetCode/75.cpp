#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void heapify(vector<int> &nums, int N, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2 ;
        if(l < N && nums[l] < nums[largest])
        {
            largest = i;
        }
        if(r < N && nums[r] < nums[largest])
        {
            largest = i;
        }
        if(largest != i)
        {
            swap(nums[largest], nums[i]);
            heapify(nums, N, largest);
        }
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(nums, n, i);
        }
        for(int i = n - 1; i > 0; i--)
        {
            swap(nums[i], nums[0]);
            heapify(nums, i, 0);
        }
    }   
};

int main()
{

    return 0;
}