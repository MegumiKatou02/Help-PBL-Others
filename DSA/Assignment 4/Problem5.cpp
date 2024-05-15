
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

    void inOrder(Node *root) {
        if(root == nullptr) return;
        stack<Node*> st;
        st.push(root);
        bool key = false;
        bool backtrack = false;
        while(!st.empty())
        {
            Node *current  = st.top();
            if(!backtrack)
            {
                if(current->left != nullptr)
                {
                    st.push(current->left);
                    continue;
                }
            }
            if(current->left == nullptr || backtrack) 
            {
                cout << current->data << " ";
                st.pop();
                key = true;
                backtrack = true;
            }                                                                                         
            if(key)
            {
                if(current->right != nullptr)
                {
                    st.push(current->right);
                    backtrack = false;
                }
                key = false;
            }
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
  
    myTree.inOrder(root);

    return 0;
}