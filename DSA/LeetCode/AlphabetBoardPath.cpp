#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    void PathNode(string &path, int size, int cmp, bool tate)
    {
        if(tate)
        {
            if(cmp < 0) path.insert(path.size(), size, 'D');
            else path.insert(path.size(), size, 'U');
        }
        else 
        {
            if(cmp < 0) path.insert(path.size(), size, 'R');
            else path.insert(path.size(), size, 'L');
        }
    }
    string alphabetBoardPath(string target) {
        int a = 0; char stand = 'a';
        string path = "";
        for(int i = 0; i < target.length(); i++)
        {
            int b = target[i] - 'a';
            int rA = a / 5; int modA = a % 5;
            int rB = b / 5; int modB = b % 5;
            int z = (rA < rB) ? abs(rA - rB) : -abs(rA - rB);
            cout << rA - rB << " " << modA - modB << " : " << a + abs(rA - rB)*5 << endl;
            
            if(a + z*5 > 25)
            {   
                PathNode(path, abs(modA - modB), modA - modA, false);
                PathNode(path, abs(rA - rB), rA - rB, true);
            }
            else
            {   
                PathNode(path, abs(rA - rB), rA - rB, true);
                PathNode(path, abs(modA - modB), modA - modB, false);
            }
            
            path += '!';
            a = b;
            stand = target[i];
            // cout << path << endl;
        }
        return path;
    }
};

int main()
{ //"DDR!UURRR!!DDD!"
    Solution s;
    cout << s.alphabetBoardPath("zb");
    return 0;
}