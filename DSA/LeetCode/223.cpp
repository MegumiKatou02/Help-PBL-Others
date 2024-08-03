#include <bits/stdc++.h>

using namespace std;

struct Rec
{
    pair<int, int> leftUp, leftDown;
    pair<int, int> rightUp, rightDown;
    Rec(pair<int, int> leftDown, pair<int, int> rightUp)
    {
        this->leftDown = leftDown;
        this->rightUp = rightUp;
        this->rightDown = {rightUp.first, leftDown.second};
        this->leftUp = {leftDown.first, rightUp.second};
    }
};

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        Rec a({ax1, ay1}, {ax2, ay2});
        Rec b({bx1, by1}, {bx2, by2});
        
        if(b.rightUp <= a.rightUp)
        {
            
        }
    }
};