#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    void Trim(string &s)
    {
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                s = s.substr(0, i + 1);
                return;    
            }
        }
    }
    vector<string> toVector(const string &s, int &maxSize)
    {
        vector<string> v;
        stringstream ss(s);
        string empty;
        while(ss >> empty)
        {
            if(empty.length() > maxSize) maxSize = empty.length();
            v.push_back(empty);
        }
        return v;
    }
    vector<string> printVertically(string s) {
        int maxSize = 0; vector<string> ns = toVector(s, maxSize);
        vector<string> v(maxSize, "");
        for(string &str : ns)
        {
            for(int i = 0; i < maxSize; i++)
            {
                if(i < str.length())
                    v[i] += str[i];
                else 
                {
                    v[i] += " ";
                }
            }
        }   
        for(string &x : v)
        {
            Trim(x);
        }
        return v;
    }
};

int main()
{
    Solution s;
    vector<string> t = s.printVertically("AA BBB C DDDD EEEEE F");
    for(auto x : t)
    {
        cout << x << "|\n";
    }

    return 0;
}