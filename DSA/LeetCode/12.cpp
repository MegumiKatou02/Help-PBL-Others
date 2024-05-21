#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long binpow(const int &a, const int &n)
    {
        if(!n) return 1;
        long long res = binpow(a, n/2);
        if(n % 2) return a * res * res;
        else return res * res;
    }
    string intToRoman(int num) {
        string sum = "";

        map<int, string> mp = {{1, "I"}, {5, "V"}, {4, "IV"}, {9, "IX"}, {10, "X"},
                              {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"},
                              {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}};
        string str = to_string(num);
        int n = str.length();
        for(int i = 0; i < n; i++) // 3749 // MMM
        {
            int first = stoi(string(1, str[i]));
            int second = binpow(10, n - i - 1);
            int standard = first * second;
            
            // cout << standard << "\n";
            if(first == 4 || first == 9)
            { 
                sum = sum + mp[standard];
                continue;
            }
            if(first != 1 && first != 5)
            {
                if(first < 5)
                {
                    standard = binpow(10, n - i - 1);
                }
                else 
                {
                    standard = 5 * binpow(10, n - i - 1);
                    sum = sum + mp[standard];
                    first = first - 5;
                    standard = binpow(10, n - i - 1);
                }       
            }
            else first = 1;
            for(int i = 1; i <= first; i++)
            {
                sum = sum + mp[standard];
            }
        }
        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.intToRoman(3612);
    
    return 0;
}