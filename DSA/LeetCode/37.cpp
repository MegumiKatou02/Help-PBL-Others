#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int N = 9;
    map<int, int[10]> mp;
    map<int, set<int>> cell;
    int dx[9], dy[9];
public:
    Solution() 
    {
        dx[0] = 1, dx[1] = -1, dx[2] = 0, dx[3] = 0;
        dx[4] = -1, dx[5] = -1, dx[6] = 1, dx[7] = 1, dx[8] = 0;

        dy[0] = 0, dy[1] = 0, dy[2] = 1, dy[3] = -1;
        dy[4] = 1, dy[5] = -1, dy[6] = 1, dy[7] = -1, dy[8] = 0;
    }
    int Center(int k)
    {
        if(k >= 0 && k <= 2)
            return 1;
        if(k >= 3 && k <= 5)
            return 4;
        return 7;
    }
    pair<int, int> CenterCell(int i, int j)
    {
        return {Center(i), Center(j)};
    }
    vector<int> LoadCell(const vector<vector<char>>& board, int i, int j)
    {
        vector<int> v;
        if(board[i][j] != '.')
            v.push_back(board[i][j] - '0');
        for(int k = 0; k < 8; k++)
        {
            int x = dx[k] + i;
            int y = dy[k] + j;
            if(board[x][y] != '.')
            {
                v.push_back(board[x][y] - '0');
            }
        }
        return v;
    }
    void Mark(vector<int> &v, int i, int j) // neu co trong 'v' thi se danh dau la 1
    {
        int key = i * 10 + j;
        fill(mp[key], mp[key] + 10, 0);
        for(const int &x : v)
        {
            mp[key][x] = 1;
        }
        
    }
    void UnMark(vector<int> &v, int i, int j) // danh dau la 1 neu khong co trong v
    {
        Mark(v, i, j);
        int key = i * 10 + j;
        for(int k = 1; k <= 9; k++)
        {
            if(mp[key][k] == 1)
            {
                mp[key][k] = 0;
            }
            else mp[key][k] = 1;
        }
    }
    vector<int> CheckHangNgang(vector<vector<char>> &board, int i)
    {
        vector<int> v;
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] != '.')
            {
                v.push_back(board[i][j] - '0');
            }
        }
        return v;
    }
    vector<int> CheckHangDoc(vector<vector<char>> &board, int j)
    {
        vector<int> v;
        for(int i = 0; i < N; i++)
        {
            if(board[i][j] != '.')
            {
                v.push_back(board[i][j] - '0');
            }
        }
        return v;
    }
    vector<int> Com3Condition(vector<int> a, vector<int> b, vector<int> c)
    {
        // a: cell, b: row, c: col
        vector<int> contains;
        contains.reserve(a.size() + b.size() + c.size());
        contains.insert(contains.end(), a.begin(), a.end());
        contains.insert(contains.end(), b.begin(), b.end());
        contains.insert(contains.end(), c.begin(), c.end());

        set<int> s(contains.begin(), contains.end());

        vector<int> result(s.begin(), s.end());

        return result;
    }
    bool CheckOnlyNumber(int i, int j)
    {
        int key = i * 10 + j; int count = 0;
        for(int k = 1; k <= 9; k++)
        {
            if(mp[key][k] == 1)
            {
                count++;
            }
        }
        return count == 1;
    }
    int GetOnlyNumber(int i, int j)
    {
        if(CheckOnlyNumber(i, j))
        {
            for(int k = 1; k <= 9; k++)
            {
                if(mp[i * 10 + j][k] == 1)
                {
                    return k;
                }
            }
        }
        return -1;
    }
    void Check3Place(vector<vector<char>> &board, int i, int j) // kiem tran tung vung/hang/cot xung quan toa do do
    {
        pair<int, int> p = CenterCell(i, j);

        //cell
        for(int k = 0; k < 8; k++)
        {
            int xi = dx[k] + p.first;
            int yi = dy[k] + p.second;
            if(xi < N && yi < N && board[xi][yi] == '.' && CheckOnlyNumber(xi, yi))
            {
                char key = GetOnlyNumber(xi, yi) + '0';
                AddNumber(board, {xi, yi}, key);
                DeleteMark3Place(board, xi, yi, key - '0');
                Check3Place(board, xi, yi);
            }
        }
        // row
        for(int k = 0; k < 9; k++)
        {
            if(board[i][k] == '.' && CheckOnlyNumber(i, k))
            {
                char key = GetOnlyNumber(i, k) + '0';
                AddNumber(board, {i, k}, key);
                DeleteMark3Place(board, i, k, key - '0');
                Check3Place(board, i, k);
            }
            if(board[k][j] == '.' && CheckOnlyNumber(k, j))
            {
                char key = GetOnlyNumber(k, j) + '0';
                AddNumber(board, {k, j}, key);
                DeleteMark3Place(board, k, j, key - '0');
                Check3Place(board, k, j);
            }
        }
        
    }
    void DeleteMark3Place(vector<vector<char>> &board, int i, int j, int val_mark)
    {
        pair<int, int> p = CenterCell(i, j);
        
        for(int k = 0; k < 9; k++)
        {
            int x = dx[k] + p.first;
            int y = dy[k] + p.second;
            mp[x * 10 + y][val_mark] = 0;
        }

        for(int k = 0; k < N; k++) {
            mp[i * 10 + k][val_mark] = 0;
        }

        for(int k = 0; k < N; k++) {
            mp[k * 10 + j][val_mark] = 0;
        }
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        // step 1
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if(board[i][j] == '.')
                {
                    vector<int> cell = LoadCell(board, Center(i), Center(j));
                    vector<int> hang = CheckHangNgang(board, i);
                    vector<int> cot = CheckHangDoc(board, j);
                    vector<int> result = Com3Condition(cell, hang, cot);
                    UnMark(result, i, j);
                    if(CheckOnlyNumber(i, j))
                    {
                        int key = GetOnlyNumber(i, j);
                        char key1 = key + '0';
                        AddNumber(board, {i, j}, key1);
                        DeleteMark3Place(board, i, j, key);
                        Check3Place(board, i, j);
                    }
                   
                }
            }
        }
        // step 2
        Filter(board, true);
        // // duyet tung cell de xac phan tu doc lap
        while(!isFull(board))
        {
            vector<pair<int, int>> pa = OriginCell();
            for(const pair<int, int> p : pa)
            {
                for(const auto c : cell[p.first * 10 + p.second])
                {
                    int count = 0;
                    int idx_x = -1, idx_y = -1;
                    for(int k = 0; k < 9; k++)
                    {
                        int xd = dx[k] + p.first;
                        int yd = dy[k] + p.second;
                        if(mp[xd * 10 + yd][c] == 1)
                        {
                            count++;
                            idx_x = xd; idx_y = yd;
                        }
                        // if(CheckOnlyNumber(xd, yd))
                        // {
                        //     cout << "ABOVEEE " << xd << " - " << yd << c << endl;
                        //     int A = GetOnlyNumber(xd, yd);
                        //     AddNumber(board, {xd, yd}, A + '0');
                        //     DeleteMark3Place(board, xd, yd, A);
                        //     Check3Place(board, xd, yd);
                        // }
                    }
                    if(count == 1)
                    {
                        char A = c + '0';
                        AddNumber(board, {idx_x, idx_y}, A);
                        DeleteMark3Place(board, idx_x, idx_y, c);
                        Check3Place(board, idx_x, idx_y);
                    }
                }
            }
        }

        // cout << "-------------------\n";
        // for(int i = 0; i < N; i++)
        // {
        //     for(int j = 0; j < N; j++)
        //     {
        //         cout << "(" << i << ", " << j << "): ";
        //         for(int k = 1; k <= 9; k++)
        //         {
        //             if(mp[i * 10 + j][k] == 1)
        //             {
        //                 cout << k << " ";
        //             }
        //         }
        //         cout << endl;
        //     }
        // }

    }

    bool isFull(const vector<vector<char>> &board) const
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(board[i][j] == '.')
                {
                    return false;
                }
            }
        }
        return true;
    }
    void AddNumber(vector<vector<char>> &board, pair<int, int> index, char A)
    {
        board[index.first][index.second] = A;
    }
    vector<pair<int, int>> OriginCell()
    {
        return {
                    {1, 1}, {1, 4}, {1, 7},
                    {4, 1}, {4, 4}, {4, 7},
                    {7, 1}, {7, 4}, {7, 7}
                };
    }
    void Filter(vector<vector<char>> &board, bool afterFilter)
    {
        vector<pair<int, int>> pa = OriginCell();
        for(const pair<int, int> &p : pa)
        {
            vector<int> v = LoadCell(board, p.first, p.second);
            for(int k = 0; k < 9; k++)
            {
                int x = dx[k] + p.first;
                int y = dy[k] + p.second;

                for(const auto &m : v)
                {
                    if(mp[x * 10 + y][m] == 1)
                    {
                        mp[x * 10 + y][m] = 0;
                    }
                }
            }
        }
        // sau khi da filter xong
        if(afterFilter)
        {
            AfterFilter(pa);
        }
    }
    void AfterFilter(const vector<pair<int, int>> &pa)
    {
        for(const pair<int, int> p : pa)
        {
            for(int k = 0; k < 9; k++)
            {
                int x = dx[k] + p.first;
                int y = dy[k] + p.second;
                AddArrToSet(this->cell[p.first * 10 + p.second], mp[x * 10 + y]);
            }
        }
    }
    void AddArrToSet(set<int> &st, int arr[])
    {
        for(int i = 1; i <= 9; i++)
        {
            if(arr[i] == 1)
            {
                st.insert(i);
            }
        }
    }
};  

int main()
{
    Solution s;
    vector<vector<char>> c = {
                {'.', '.', '2', '.', '1', '.', '3', '7', '8'},
                {'.', '1', '5', '.', '6', '3', '4', '2', '9'},
                {'.', '.', '4', '9', '.', '.', '.', '.', '1'},
                {'9', '4', '.', '1', '.', '7', '.', '.', '.'},
                {'1', '.', '8', '.', '.', '.', '7', '.', '.'},
                {'.', '.', '.', '.', '8', '.', '1', '.', '.'},
                {'2', '8', '.', '5', '4', '.', '.', '1', '.'},
                {'.', '.', '.', '.', '.', '.', '2', '.', '7'},
                {'3', '5', '.', '6', '7', '2', '9', '8', '.'}
            };
    vector<vector<char>> board = {
                                    {'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}
                                };
    s.solveSudoku(c);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}