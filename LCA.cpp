#include <iostream>


using namespace std;

struct Node{
	int value;
	Node *left;
	Node *right;
};

Node *tree(int *num, int len, int indx);

int main() {
	const int LEN = 15;
	int nums[LEN] = {3, 11, 5, 2, 6, 17, 4, 7, 9, 13, 21, 14, 8, 19, 21};
	Node *root = tree(nums, LEN, 0);

	cout << root->left->right->right->value << '\n';

};

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