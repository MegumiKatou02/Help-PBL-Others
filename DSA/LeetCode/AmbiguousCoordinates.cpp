#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public: 
    /*
        (12345)
        2 -> 5
    */
    vector<string> ambiguousCoordinates(string S) {
        for (int i = 2; i < S.size() - 1; i++) {
            string strs[2] = {S.substr(1,i-1), S.substr(i,S.size()-i-1)};
            // cout << "in" << endl;
            xPoss.clear();
            for (int j = 0; j < 2; j++)
                if (xPoss.size() > 0 || j == 0) parse(strs[j], j);
        }
        return ans;
    }
private:
    vector<string> ans, xPoss;
    void parse(string str, int xy) {
        if (str.size() == 1 || str.front() != '0')
            process(str, xy);
        if (str.size() > 1 && str.back() != '0')
            process(str.substr(0,1) + "." + str.substr(1), xy);
        if (str.size() > 2 && str.front() != '0' && str.back() != '0')
            for (int i = 2; i < str.size(); i++)
                process(str.substr(0,i) + "." + str.substr(i), xy);
    }
    void process(string str, int xy) {
        if (xy)
            for (auto x : xPoss)
                ans.push_back("(" + x + ", " + str + ")");
        else xPoss.push_back(str);
    }
};

int main()
{
    Solution s;
    // s.ambiguousCoordinates("(12345)");
    string t = "1234ledinhchinh";
    cout << t.substr(4, 3);

    return 0;
}