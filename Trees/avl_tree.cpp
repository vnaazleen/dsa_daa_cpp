#include <iostream>
#include <stdlib.h>
using namespace std;


/**
 * @brief  Node structure represent a node in a AVL tree
 *
 */
struct Node {
	int data;
	int height;
	struct Node* left;
	struct Node* right;
};

class AVLTreeADT {
	public:
		struct Node *insert(struct Node *, int);
		struct Node *remove(struct Node *, int);
		struct Node *search(struct Node *, int);
		void inorder(struct Node *);
		void preorder(struct Node *);
		void postorder(struct Node *);
		void printTree(struct Node *, int);
	private:
		int bf(struct Node *);
		int height(struct Node * node);
		struct Node * LL(struct Node *);
		struct Node * LR(struct Node *);
		struct Node * RR(struct Node *);
		struct Node * RL(struct Node *);
		struct Node * findMax(struct Node *);
		struct Node * findMin(struct Node *);
};

/**
 * @brief returns height of node in a tree
 *
 * @param node
 * @return int
 */
int AVLTreeADT :: height(struct Node* t) {
	if(t == NULL)
		return -1;
	return 1 + max(height(t->left), height(t->right));
}

/**
 * @brief  returns balance factor of a node in tree
 *
 * @param t
 * @return int
 */
int AVLTreeADT :: bf(struct Node* t) {
	return abs(height(t->left) - height(t->right));
}

/**
 * @brief inserts a node into avl tree
 *
 * @param t
 * @param val
 * @return struct Node*
 */
struct Node* AVLTreeADT :: insert(struct Node* t, int val) {
	// if the tree is empty, we will create root node with given data
	if (t == NULL) {
		t = (struct Node *) malloc(sizeof(struct Node));
		t->left = NULL;
		t->right = NULL;
		t->height = 0;
		t->data = val;
	} else if (t->data > val) {
		// if the val is less than root node's value, we will insert it in left subtree
		t->left = insert(t->left, val);

		// check for AVL tree property (Balance factor)
		int b = bf(t);

		// bf should be either, [0, 1] otherwise avl tree property violates, so perform rotation
		if (b >= 2) {
			if (t->left->data > val) {
				// now we know that val is insert at root's left of left's subtree => LL rotation
				t = LL(t);
			} else {
				// other case is root's left of right subtree => LR rotation
				t = LR(t);
			}
		}
	} else if (t->data < val) {
		// if the val is greater than root node's value, we will insert it in right subtree
		t->right = insert(t->right, val);

		// check for AVL tree property (Balance factor)
		int b = bf(t);

		// bf should be either, [0, 1] otherwise avl tree property violates, so perform rotation
		if (b >= 2) {
			if (t->right->data < val) {
				// now we know that val is insert at root's right of right's subtree => RR rotation
				t = RR(t);
			} else {
				// other case is root's right of left subtree => RL rotation
				t = RL(t);
			}
		}
	} else {
		cout << val << " is already present in tree. (duplicates are not allowed)" << endl;
	}

	t->height = height(t);
	return t;
}


struct Node* AVLTreeADT :: remove(struct Node *t, int k) {
	struct Node* tmp;
	if(t == NULL) {
		return NULL;
	} 

	if(k < t->data) {
		t->left = remove(t->left, k);
		// check for AVL tree property (Balance factor)
		int b = bf(t);

		// bf should be either, [0, 1] otherwise avl tree property violates, so perform rotation
		if (b >= 2) {
			if (t->right->right) {
				t = RR(t);
			} else {
				t = RL(t);
			}
		}
	} else if (k > t->data) {
		t->right = remove(t->right, k);

		// check for AVL tree property (Balance factor)
		int b = bf(t);

		// bf should be either, [0, 1] otherwise avl tree property violates, so perform rotation
		if (b >= 2) {
			if (t->left->left) {
				t = LL(t);
			} else {
				t = LR(t);
			}
		}
	} else if(t->left && t->right) {
		tmp = findMin(t->right);
		t->data = tmp->data;
		t->right = remove(t->right, t->data);
		tmp = NULL;
	} else {
		tmp = t;
		if(t->left == NULL)
			t = t->right;
		else if(t->right == NULL)
			t = t->left;
		delete tmp;
		tmp = NULL;
	}

	return t;
}

struct Node * AVLTreeADT :: LL(struct Node *t) {
	/*
			t
		  /					temp
		temp    ---->      /    \
		/  \			  L      t
	   L    R					/
	   						   R
	*/

	// perform rotation
	struct Node *temp;
	temp = t->left;
	t->left = temp->right;
	temp->right = t;

	// balance height
	t->height = height(t);
	temp->height = height(temp);

	// return root
	return temp;
}

struct Node * AVLTreeADT :: RR(struct Node *t) {
	/*
			t
			  \ 					temp
			  temp   ----->       /     \
			  /   \              t		 R
			 L     R 			  \
			 						L
	*/
	// perform rotation
	struct Node *temp;
	temp = t->right;
	t->right = temp->left;
	temp->left = t;

	// balance height
	t->height = height(t);
	temp->height = height(temp);

	// return root
	return temp;
}

struct Node * AVLTreeADT :: LR(struct Node *t) {
	t->left = RR(t->left);
	return LL(t);
}

struct Node * AVLTreeADT :: RL(struct Node *t) {
	t->right = LL(t->right);
	return RR(t);
}

struct Node * AVLTreeADT :: search(struct Node *t, int data) {
	if (t == NULL) {
		return NULL;
	} else if (t-> left == NULL && t->right == NULL) {
		if(t->data == data) {
			return t;
		} return NULL;
	} else if (t->data > data) {
		return search(t->left, data);
	} else if (t-> data < data) {
		return search(t->right, data);
	} else {
		return t;
	}
}

void AVLTreeADT :: inorder(struct Node *t) {
	if(t == NULL) {
		return;
	}
	inorder(t->left);
	cout << t->data << " ";
	inorder(t->right);
}

void AVLTreeADT :: preorder(struct Node *t) {
	if(t == NULL) {
		return;
	}
	cout << t->data << " ";
	inorder(t->left);
	inorder(t->right);
}

void AVLTreeADT :: postorder(struct Node *t) {
	if(t == NULL) {
		return;
	}
	inorder(t->left);
	inorder(t->right);
	cout << t->data << " ";
}

struct Node * AVLTreeADT :: findMin(struct Node *t) {
	if (t == NULL) {
		return NULL;
	} else if (t->left != NULL) {
		return findMin(t->left);
	}
	return t;
}

struct Node * AVLTreeADT :: findMax(struct Node *t) {
	if (t == NULL) {
		return NULL;
	} else if (t->right != NULL) {
		return findMax(t->right);
	}
	return t;
}

void AVLTreeADT :: printTree(struct Node *t,int level)
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
	AVLTreeADT avl_obj;

	int n;
	for(int i = 0; i <10; i++) {
		cout<< "Enter node value to insert: " << endl;
		cin >> n;
		root = avl_obj.insert(root, n);

		avl_obj.inorder(root);
		cout<<endl;
		avl_obj.printTree(root, 0);
		cout<<endl;
	}

	for(int i = 0; i <5; i++) {
		cout<< "Enter node value to remove: " << endl;
		cin >> n;
		root = avl_obj.remove(root, n);

		avl_obj.inorder(root);
		cout<<endl;
		avl_obj.printTree(root, 0);
		cout<<endl;
	}
}
