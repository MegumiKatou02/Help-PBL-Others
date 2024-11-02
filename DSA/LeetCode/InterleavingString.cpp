#include <iostream>

using namespace std;

class Solution {
public:
    //ababcqmq
    //abqm
    //abcq
    bool isInterleave(string s1, string s2, string s3) {
        int idx3 = 0;
        int x = 0;
        int y = 0;
        string sx = "", sy = "";
        pair<bool, bool> turn = {false, false};
        while(idx3 < s3.length())
        {
            if(turn == make_pair(false, false) || turn == make_pair(true, false))
            {
                while(s3[idx3] == s1[x] && x < s1.length())
                {
                    sx += s1[x];
                    idx3++;
                    x++; 
                    turn = {false, true};
                }
            }
            else 
            {
                if(sx == sy) turn = {false, true}; // change round
                else return false;
            }
            if(turn == make_pair(false, false) || turn == make_pair(false, true))
            {
                while(s3[idx3] == s2[y] && y < s2.length())
                {
                    sy += s2[y];
                    idx3++;
                    y++; 
                    turn = {true, false};
                }
            }
            else 
            {
                if(sx == sy) turn = {true, false}; // change round
                else return false;
            }
            if(turn == make_pair(false, false)) return false;
        }
        if(sx != s1 || sy != s2) return false;
        return true;
    }
};

int main()
{
    Solution s;
    if(s.isInterleave("aabcc", "dbbca", "aadbbcbcac"))
    {
        cout << "Yes\n";
    }
    else cout << "No\n";

    return 0;
}