#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

class Solution {
private:
    vector<string> v;
public:
    void FindPath(vector<vector<char>>& board, string word, int idx, pair<int, int> p)
    {
        cout << board[p.first][p.second] << endl;
        if(idx >= word.length()) 
        {
            if(board[p.first][p.second] == word[idx - 1])
            {
                v.push_back(word);
            }
            return;
        }
        if(idx < word.length() && board[p.first][p.second + 1] == word[idx])
        {
            FindPath(board, word, idx + 1, {p.first, p.second + 1});
        }
        if(idx < word.length() && board[p.first + 1][p.second] == word[idx])
        {
            FindPath(board, word, idx + 1, {p.first + 1, p.second});
        }
        if(idx < word.length() && board[p.first][p.second - 1] == word[idx])
        {
            FindPath(board, word, idx + 1, {p.first, p.second - 1});
        }
        if(idx < word.length() && board[p.first - 1][p.second] == word[idx])
        {
            FindPath(board, word, idx + 1, {p.first - 1, p.second});
        }
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0])
                {
                    FindPath(board, word, 1, {i, j});
                    cout << v[0] << endl;
                    if(!v.empty() && v[0] == word)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = {
                                    {'A','B','C','E'},
                                    {'S','F','C','S'},
                                    {'A','D','E','E'}
                                };
    if(s.exist(board, "ABC"))
        cout << "YES";
    else cout << "NO";

    return 0;
}