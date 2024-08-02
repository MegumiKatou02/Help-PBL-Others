#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 1) return true;
        pair<int, int> p = {prerequisites[0][0], prerequisites[0][1]};
        for(int i = 1; i < numCourses; i++)
        {
            if(prerequisites[i][0] != p.first)
                return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}