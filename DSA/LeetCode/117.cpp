#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* SetRight(Node *root)
    {
        Node *empty = new Node();
        while(root != nullptr)
        {
            root->next = empty;
            root = root->right;
        }
        return empty;
    }
    Node* connect(Node* root) {
        if(!root) return nullptr;
        Node *empty = SetRight(root);

        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node *v = q.front();
            q.pop();
            
        }
    }
};

int main()
{

    return 0;
}