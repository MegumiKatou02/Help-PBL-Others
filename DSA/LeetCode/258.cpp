#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
        if(s.length() == 1) return num;
        while(true)
        {
            int n = 0;
            for(const char &x : s)
            {
                int a = x - '0';
                n += a;
            }
            s = to_string(n);
            if(s.length() <= 1)
            {
                // return stoi(s);
                break;
            }

        }
        return stoi(s);
    }
};

int main()
{
    Solution s;
    cout << s.addDigits(38) << endl;
    return 0;
}