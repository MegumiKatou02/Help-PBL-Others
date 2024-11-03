#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        sort(products.begin(), products.end());

        for(int i = 0; i < searchWord.length(); i++)
        {
            vector<string> v; 
            string s = searchWord.substr(0, i + 1);
            for(int j = 0;  j < products.size(); j++)
            {
                string m = products[j].substr(0, i + 1);
                if(s == m)
                {
                    if(v.size() <= 2) v.push_back(products[j]);
                }
                else 
                {
                    products.erase(products.begin() + j);
                    j--;
                }
            }
            result.push_back(v);
        }
        for(auto x : result)
        {
            for(auto y : x)
            {
                cout << y << " ";
            }
            cout << "\n";
        }
        return result;
    }
};

int main()
{
    vector<string> t = {"mobile","mouse","moneypot","monitor","mousepad"};
    Solution s;
    s.suggestedProducts(t, "mouse");

    return 0;
}