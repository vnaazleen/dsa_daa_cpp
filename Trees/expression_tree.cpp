/**
 * @file expression_tree.cpp
 * @author Shaik Vaseem Naazleen
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;

struct Node {
    char data;
    struct Node *left, *right;
    Node(char data)
    {
        this->data = data;
        left = right = NULL;
    }
};

int precedence(char c) {
    switch(c) {
        case '+': 
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '%':
        case '^':
            return 3;
    }
    return -1;
}

string infix_to_postfix(string infix) {
    stack<char> s;
    string postfix = "";
    for (int i = 0; i < infix.size(); i++) {
        char c = infix[i];

        // if c is a alphabet, the add to postfix expression
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
            postfix += c;
        } 
        // open bracket push it to stack
        else if ( c == '(') {
            s.push(c);
        } 
        // closing bracket, pop items until open bracket and add them to postfix
        else if ( c == ')') {
            while ( s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            // if c is operator
            if (s.empty()) {
                s.push(c);
            }
            else if (precedence(c) > precedence(s.top())) {
                s.push(c);
            } else {
                while (!s.empty() && precedence(c) <= precedence(s.top())) {
                    postfix += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
    }

    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

Node* build_exp_tree(string postfix) {
    stack<Node*> s;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // if current char is a alphabet then create a node & push into stack
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
            struct Node* cur = new Node(c);
            s.push(cur);
        } else { // if operand, pop 2 characters from stack and make a tree like structure
            Node* a = s.top();
            s.pop();
            Node* b = s.top();
            s.pop();

            struct Node* cur = new Node(c);

            // build tree 
            //    c
            //  /  \
            // b    a

            cur->left = b;
            cur->right = a;

            // push cur node back to stack 
            s.push(cur);
        }

    }

    return s.top();
}

void inorder_traversal(struct Node* node)
{
    if (node == NULL)
        return;
 
    // left child
    inorder_traversal(node->left);
 
    // root
    cout << node->data << " ";
 
    // right child
    inorder_traversal(node->right);
}

void preorder_traversal(struct Node* node)
{
    if (node == NULL)
        return;

    // root
    cout << node->data << " ";
 
    // left child
    preorder_traversal(node->left);
 
    // right child
    preorder_traversal(node->right);
}

void postorder_traversal(struct Node* node)
{
    if (node == NULL)
        return;
 
    // left child
    postorder_traversal(node->left);
  
    // right child
    postorder_traversal(node->right);

    // root
    cout << node->data << " ";
}

// Driver code
int main()
{
    // Given a infix string, converts it to expression tree and prints inorder, preorder, and post order expressions 
    string s;
    cin >> s;
    string postfix = infix_to_postfix(s);
    Node* exp_tree = build_exp_tree(postfix);

    cout << "Inorder: ";
    inorder_traversal(exp_tree);
    cout<<endl;

    cout << "Preorder: ";
    preorder_traversal(exp_tree);
    cout<<endl;

    cout << "Postorder: ";
    postorder_traversal(exp_tree);
    cout<<endl;

}
