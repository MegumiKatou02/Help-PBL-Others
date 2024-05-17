
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

    void postOrder(Node *root) {
        if(root == nullptr) 
            return;
        stack<Node*> st;
        st.push(root);
        bool backtrack = false;
        int oldData = root->data;
        while(!st.empty())
        {
            Node *current = st.top();
            if(current->left != nullptr) {
                if(!backtrack) {
                    st.push(current->left);
                    continue;
                }
            }
            if(current->right != nullptr) {
                if(current->right->data != oldData) {
                    st.push(current->right);
                    backtrack = false;
                    continue;
                }
            }
            cout << current->data << " ";
            st.pop();
            backtrack = true; // di len
            oldData = current->data;
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
  
    myTree.postOrder(root);

    return 0;
}

/*
1
-1
2
5
3
6
4
-4
0
-5
-3
-2

13
1
-1
2
5
3
6
4
-5
0
-6
-3
-4
-2
*/