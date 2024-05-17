
#include <bits/stdc++.h>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void preOrder(Node *root) {
        if(root == nullptr)
        {
            return;
        }
        stack<Node*> leftSide;
        stack<Node*> rightSide;
        leftSide.push(root);
        while(!(leftSide.empty() && rightSide.empty()))
        {
            Node *current = nullptr;
            if(!leftSide.empty()) 
            {
                current = leftSide.top();
                cout << current->data << " ";
                leftSide.pop();
            }
            else
            { 
                current = rightSide.top();
                cout << current->data << " ";
                rightSide.pop();
            }
            if(current->left != nullptr) leftSide.push(current->left);
            if(current->right != nullptr) rightSide.push(current->right);
        }   
    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.preOrder(root);

    return 0;
}