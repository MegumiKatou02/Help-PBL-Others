#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

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
    bool LogR(const int &n)
    {
        return (n > 0 && (n & (n - 1)) == 0);
    }
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        Node *node = root;
        while(node != nullptr)
        {
            Node temp(0);
            for(Node *res = &temp; node != nullptr; node = node->next)
            {
                if(node->left != nullptr)
                {
                    res->next = node->left;
                    res = node->left;
                }
                if(node->right != nullptr)
                {
                    res->next = node->right;
                    res = node->right;
                }
            }
            node = temp.next;
        }
        return root;
    }
};

int main()
{
    return 0;
}