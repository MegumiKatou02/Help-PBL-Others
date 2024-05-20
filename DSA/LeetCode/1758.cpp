#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int steps1 = 0, steps2 = 0;
        char first = '1', second = '0';
        for(const char &op : s)
        {
            if(op != first) steps1++;
            if(op != second) steps2++;
            first = (first == '1') ? '0' : '1';
            second = (second == '1') ? '0' : '1';
        }
        return min(steps1, steps2);
    }
};
int main()
{
	Solution s;
    cout << s.minOperations("0100");
	return 0;
}