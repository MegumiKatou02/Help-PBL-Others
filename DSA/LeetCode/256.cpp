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
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        queue<pair<TreeNode*, string>> q;
        q.push({root, to_string(root->val)});

        while(!q.empty())
        {
            TreeNode *p = q.front().first;
            string parent = q.front().second;
            q.pop();
            TreeNode *left = p->left;
            TreeNode *right = p->right;
            if(left == nullptr && right == nullptr) // this is leaf node
            {
                v.push_back(parent);
            }
            if(left)
            {
                q.push({left, parent + "->" + to_string(left->val)});
            }
            if(right)
            {
                q.push({right, parent + "->" + to_string(right->val)});
            }
        }
        return v;
    }
};

int main()
{

    return 0;
}