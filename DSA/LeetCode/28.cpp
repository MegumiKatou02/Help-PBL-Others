#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle) return 0;
        int position = -1;
        for(int i = 0; i < haystack.length(); i++)
        {
            const char ch = haystack[i];
            if(ch == needle[0]) // truong hop trung it nhat mot chu cai
            {
                int t = position = i; bool check = true;
                if(haystack.substr(position).length() >= needle.length())
                {
                    int j = 0;
                    while(t < haystack.length() && j < needle.length())
                    {
                        cout << haystack[t] << " - " << needle[j] << "\n";
                        if(haystack[t] != needle[j])
                        {
                            check = false; break;
                        }
                        t++; j++;
                    }
                    if(check) return position;
                }
            }
        }
        return -1; // truong hop khong phan nao trung ca
    }
};

int main()
{

    Solution s;
    cout << s.strStr("abc", "c");

    return 0;
}