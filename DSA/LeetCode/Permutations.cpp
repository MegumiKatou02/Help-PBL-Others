#include <vector>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
    vector< vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> contains(n);
        bool visited[n + 1];
        fill_n(visited, n + 1, false);

        std::function<void(int)> dfs = [&](int depth) 
        {
            if(depth == n)
            {
                result.emplace_back(contains);
                return;
            }
            for(int i = 0; i < n; i++)
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    contains[depth] = nums[i];
                    dfs(depth + 1);
                }
                visited[i] = false;
            }
        };
        dfs(0);
        return result;
    }
};

int main()
{

    return 0;
}