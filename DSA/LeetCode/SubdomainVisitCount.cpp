#include <iostream>
#include <string>
#include <vector>
#include <map> // test git

using namespace std;

class Solution {
public:
    int CountDot(const string &s)
    {
        int count = 0;
        for(const char &x : s)
        {
            if(x == '.') count++;
        }
        return count;
    }
    // nutri.com - test.nutri.com
    void SplitNumber(string &s, int &num) {
        int idx;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                idx = i;
            }
        }
        num = stoi(s.substr(0, idx));
        s = s.substr(idx + 1);
    }

    pair<string, string> Split(string s, int &num) {
        // 1 dot or 2 dot
        SplitNumber(s, num);
        int count = 0; int x = 0, y = 0;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] == '.') {
                count++;
                if(count == 1) y = i;
                else x = i;
            }
        }
        if(x == 0) x = -1;
        return {s.substr(x + 1), s.substr(y + 1)};
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> mp;
        for(string s : cpdomains)
        {
            int num = 0;
            pair<string, string> t = Split(s, num);
            string m = s;
            SplitNumber(m, num);
            // cout << m << "\t" << t.first << "\t" << t.second << "\n";
            if(CountDot(m) != 1) {
                mp[m] += num;
            }
            mp[t.first] += num;
            mp[t.second] += num;
        }
        vector<string> vt;
        for(const pair<string, int> &p : mp)
        {
            vt.push_back(to_string(p.second) + " " + p.first);
        }
        return vt;
    }
};

int main()
{
    Solution s;
    vector<string> k {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> vt = s.subdomainVisits(k);
    for(auto x : vt)
    {
        cout << x << "\n";
    }
    return 0;
}