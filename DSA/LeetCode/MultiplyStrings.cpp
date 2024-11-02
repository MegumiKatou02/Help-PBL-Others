#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
public: // 1 2 3
    void Trim(string &s)
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != '0')
            {
                s = s.substr(i);
                return;
            }
        }
        s = "0";
    }
    queue<int> ToQueue(const string &x)
    {
        queue<int> q;
        for(int i = x.length() - 1; i >= 0; i--)
        {
            int k = x[i] - '0';
            q.push(k);
        }
        return q;
    }
    string StackToString(stack<int> q)
    {
        string s = "";
        while(!q.empty())
        {
            char x = q.top() + '0';
            q.pop();
            s += x;
        }
        return s;
    }
    string add(const string &a, const string &b)
    {
        queue<int> A = ToQueue(a);
        queue<int> B = ToQueue(b);
        int m = 0;
        stack<int> result;
        int x, y;
        while(!(A.empty() && B.empty()))
        {
            if(!A.empty() && !B.empty())
            {
                x = A.front(); A.pop();
                y = B.front(); B.pop();
            }
            else if(!A.empty())
            {
                x = A.front(); A.pop();
                y = 0;   
            }
            else
            {
                y = B.front(); B.pop();
                x = 0;   
            }
            int t = x + y + m;
            m = t / 10;
            result.push(t % 10);
        }
        result.push(m);
        return StackToString(result);
    }
    string NumberZero(const int &x, const int &y)
    {
        string s = "";
        int ref = x - y;
        for(int i = 1; i <= ref; i++)
        {
            s += "0";
        }
        return s;
    }
    string multiply(string num1, string num2) {
        vector<long long> vt;
        string s = "0"; float kTurn = 0.1;
        for(int i = num1.length() - 1; i >= 0; i--)
        {
            int x = num1[i] - '0';
            int m = 0;
            stack<int> turn;
            for(int j = num2.length() - 1; j >= 0; j--)
            {
                int y = num2[j] - '0';
                int t = x * y + m;
                m = t / 10;
                turn.push(t % 10);
            }
            turn.push(m);
            string key = NumberZero(num1.length(), i + 1);
            s = add(s, StackToString(turn) + key);
        }
        Trim(s);
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.multiply("123", "456");
    // s.add("7434", "11459");
    
    return 0;
}