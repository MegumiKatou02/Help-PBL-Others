#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        cout << s << endl;
        int i = 0;
        while(i < s.length())
        {
            cout << i << " : " << s[i] << "\n";
            string original(k, s[i]);
            size_t pos = s.find(original, i);
            while(pos != string::npos)
            {
                // かいしんのいちげき
                s.erase(pos, k);
                // ウフデート。
                pos = s.find(original, pos);
                i --;
            }
            i++;
        }
        return s;
    }
};

int main()
{ //ddbbbdaa
    Solution s;
    cout << s.removeDuplicates("deeedbbcccbdaa", 3);
    return 0;
}

//"pbbcggttciiippooaais"