#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int x = sqrt(num);
        if(x * x == num)
            return true;
        return false;
    }
};