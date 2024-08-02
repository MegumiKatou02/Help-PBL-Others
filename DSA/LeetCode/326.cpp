#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        float x = log10(n)/log10(3);
        if(pow(3, x) == n)
            return true;
        return false;
    }
};

int main()
{

    return 0;
}