#include <iostream>


using namespace std;

// For binary tree
struct Node{
	int value;
	Node *left;
	Node *right;
};

Node *tree(int *num, int len, int indx);
Node *LCA(Node *root, int node1, int node2);

int main() {
	// Create tree
	const int LEN = 15;
	int nums[LEN] = {3, 11, 5, 2, 6, 17, 4, 7, 9, 13, 21, 14, 8, 19, 1};
	Node *root = tree(nums, LEN, 0);


	Node *lca = LCA(root, 7, 9);

	cout << lca->value << endl; // 2

	lca = LCA(root, 6, 13);

	cout << lca->value << endl; // 6

	lca = LCA(root, 4, 6);

	cout << lca->value << endl; // 3

	lca = LCA(root, 17, 4);

	cout << lca->value << endl; // 5

	lca = LCA(root, 21, 2);

	cout << lca->value << endl; // 11


};

// Creates tree from array using recursion
Node *tree(int *num, int len, int indx) {
	if(indx >= len)
		return NULL;

	int left_indx = (indx * 2) + 1;
	int right_indx = left_indx + 1;

	Node *node = new Node;

	node->value = num[indx];

	node->left = tree(num, len, left_indx);

	node->right = tree(num, len, right_indx);

	return node;

};

Node *LCA(Node *root, int node1, int node2) {
	if(!root)
		return NULL;
	if(root->value == node1 || root->value == node2)
		return root;
	
	Node *left = LCA(root->left, node1, node2);
	Node *right = LCA(root->right, node1, node2);
	

	if(left && right)
		return root;


	return left ? left : right;

};







