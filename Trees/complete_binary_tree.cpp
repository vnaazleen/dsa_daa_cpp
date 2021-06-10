/**
 * @file complete_binary_tree.cpp
 * @author Shaik Vaseem Naazleen
 * @brief 
 * @version 0.1
 * @date 2021-05-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class CompleteBinaryTree {
public:
	struct Node* insert(struct Node*, int);
	void printTree(struct Node*, int);
	void inorder(struct Node*);
};

struct Node* CompleteBinaryTree :: insert(struct Node* t, int k) {

    if(t == NULL) {
        t = (struct Node *)malloc(sizeof(struct Node *));
        t->data = k;
        t->left = t->right = NULL;
        return t;
    }

    queue<struct Node *> q;
    q.push(t);
    while(!q.empty()) {
        struct Node * temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = (struct Node *)malloc(sizeof(struct Node));
			temp = temp->left;
			temp->data = k;
			temp->left = temp->right = NULL;
			return t;
        } else if (temp->right == NULL) {
            temp->right = (struct Node *)malloc(sizeof(struct Node));
			temp = temp->right;
			temp->data = k;
			temp->left = temp->right = NULL;
            return t;
        } else {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return t;
}

void CompleteBinaryTree :: inorder(struct Node *t) {
	if(t == NULL) {
		return;
	}

	inorder(t->left);
	cout << t->data << " ";
	inorder(t->right);
}

void CompleteBinaryTree :: printTree(struct Node *t,int level)
{
		if(t!=NULL)
		{
			printTree(t->right, level+1);
			for(int i=0;i<level;i++)
				cout<<"  ";
			cout<<t->data<<"\n";
			printTree(t->left, level+1);
		}
}

int main() {
    struct Node* root = NULL;  // empty tree
	CompleteBinaryTree cbt_obj;

	int n;
	for(int i = 0; i <10; i++) {
		cout<< "Enter node value: " << endl;
		cin >> n;
		root = cbt_obj.insert(root, n);

	    cbt_obj.printTree(root, 0);
		cout<<endl;
	}
}