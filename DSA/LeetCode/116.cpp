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
private:
    bool visited[101];
    bool end[101];
    bool first[101];
public:
    Solution()
    {
        fill(visited, visited + 101, false);
        fill(end, end + 101, false);
        fill(first, first + 101, false);
    }
    void insert(Node *&root, int k)
    {
        if(root != nullptr)
        {
            if(k > root->val)
                insert(root->right, k);
            else if(k < root->val)
                insert(root->left, k);
        }
        else root = new Node(k);
    }
    void print(Node *root)
    {
        if(root != nullptr)
        {
            cout << root->val << "\n";
            print(root->left);
            print(root->right);
        }
    }
    Node* connect(Node* root) {
        
    }
    void Mark(Node *root)
    {
        if(root != nullptr)
        {
            visited[root->val] = true;
            Mark(root->right);
        }
    }
    void MarkFirst(Node *root)
    {
        if(root != nullptr)
        {
            visited[root->val] = true;
            MarkFirst(root->left);
        }
    }
    void solve(Node *root)
    {
        if(root == nullptr) return;
        queue<Node*> q;
        visited[root->val] = true;
        q.push(root);
        Node *prev = nullptr;
        while(!q.empty())
        {
            Node* v = q.front();
            q.pop();
            Node *left = v->left;
            Node *right = v->right;
            cout << v->val << " ";
            if(first[v->val])
            {
                prev = v;   
            }
            if(v->left && !visited[left->val])
            {
                q.push(left);
                visited[left->val] = true;
            }
            if(v->right && !visited[right->val])
            {
                q.push(right);
                visited[right->val] = true;
            }
        }
    }
};

int main()
{

    Solution s;
    Node *root = nullptr;
    s.insert(root, 4);
    s.insert(root, 2);
    s.insert(root, 6);
    s.insert(root, 1);
    s.insert(root, 3);
    s.insert(root, 5);
    s.insert(root, 7);

    // s.print(root);
    s.solve(root);

    return 0;
}