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
    void invert(TreeNode *root)
    {
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) return;

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        invert(root->left);
        invert(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        invert(root);
        return root;
    }
};