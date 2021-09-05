/* Implement Operations on Binary Search Tree non recursive. */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTreeNR {
public:
    TreeNode* root;
    BinaryTreeNR() {
        root = NULL;
    }
    void insert(int data);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    void levelOrderTraversal(); 
};

void BinaryTreeNR:: insert(int data) {
    if(root == NULL) {
        root = new TreeNode(data);
        return;
    }

    TreeNode* cur = root;

    while(cur != NULL) {
        if(cur -> val >  data) {
            if(cur -> left) {
                cur = cur -> left;
            } else {
                cur -> left = new TreeNode(data);
                return;
            }
        } else {
            if(cur -> right) {
                cur = cur -> right;
            } else {
                cur -> right = new TreeNode(data);
                return;
            }
        }
    }

    if(cur -> val < data) {
        cur -> left = new TreeNode(data);
    } else {
        cur -> right = new TreeNode(data);
    }
}

void BinaryTreeNR:: levelOrderTraversal() {
    if(root == NULL) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            TreeNode* cur = q.front();
            q.pop();

            cout << cur -> val << " ";

            if(cur -> left) {
                q.push(cur -> left);
            } 

            if(cur -> right) {
                q.push(cur -> right);
            }
        }

        cout << endl;
    }
    cout << endl;
}

void BinaryTreeNR :: inorderTraversal() {
    if(root == NULL) { return; }

    TreeNode* cur = root;
    stack<TreeNode*> s;

    while(cur != NULL || !s.empty()) {
        
        if (cur != NULL) {
            s.push(cur);
            cur = cur -> left;
        } else {
            cur = s.top();
            s.pop();

            cout << cur -> val << " ";
            cur = cur -> right;
        }
    }

    cout << endl;
}

void BinaryTreeNR :: preorderTraversal() {
    if(root == NULL) { return; }

    TreeNode* cur = root;
    stack<TreeNode*> s;

    while(cur != NULL || !s.empty()) {
        
        if(cur != NULL) {
            cout << cur -> val << " ";
            s.push(cur);
            cur = cur -> left;
        } else {
            cur = s.top();
            s.pop();

            cur = cur -> right;
        }
    }
    cout << endl;
}

void BinaryTreeNR :: postorderTraversal() {
    if(root == NULL) { return; }

    TreeNode* cur = root;
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(cur);

    while(!s1.empty()) {
        cur = s1.top();
        s1.pop();
        s2.push(cur);

        if(cur -> left) { s1.push(cur -> left); }
        if(cur -> right) { s1.push(cur -> right); }

    }

    while(!s2.empty()) {
        cout << s2.top() -> val << " ";
        s2.pop();
    }
    cout << endl;
}
 
int main() {
    BinaryTreeNR bt;
    bt.insert(6);
    bt.insert(3);
    bt.insert(1);
    bt.insert(5);
    bt.insert(8);
    bt.insert(7);
    bt.insert(9);
    bt.levelOrderTraversal();
    bt.inorderTraversal();
    bt.preorderTraversal();
    bt.postorderTraversal();
}
