#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<string> v;
public:
    int solve(TreeNode *root)
    {
        queue<pair<TreeNode*, string>> q;
        q.push({root, to_string(root->val)});
        while(!q.empty())
        {
            TreeNode *node = q.front().first;
            string parent = q.front().second;
            q.pop();

            TreeNode *left = node->left;
            TreeNode *right = node->right;
            // check if node pointer is leaf node
            if(left == nullptr && right == nullptr)
            {
                v.push_back(parent);
            }
            if(left)
                q.push({left, parent + to_string(left->val)});
            if(right)
                q.push({right, parent + to_string(right->val)});
        }
        
        int num = 0;
        for(const string &x : v)
        {
            num += stoi(x);
        }
        return num;
    }
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        return solve(root);
    }
};

int main()
{
    Solution s;
    TreeNode *root = nullptr;
    s.sumNumbers(root);
    return 0;
}