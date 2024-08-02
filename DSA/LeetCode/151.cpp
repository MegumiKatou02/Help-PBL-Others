#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> v;
        string empty = "";
        while(ss >> empty)
        {
            v.push_back(empty);
        }
        string m = "";
        for(int i = v.size() - 1; i >= 0; i--)
        {
            m += v[i];
            if(i != 0)
            {
                m += " ";
            }
        }
        return m;
    }
};

int main()
{

    return 0;
}