#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

//	tao ra 1 node
Node* createNode(int data){
//	cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//	chen 1 nut vao cai cay
Node* insertNode(Node* node, int data){
	if(node == NULL){
		 return createNode(data);
	}
	if(data < node->data ){
		node->left = insertNode(node->left, data);
	} else if(data > node->data){
		node->right = insertNode(node->right,data);
	}
	return node;
}

// ham kiem tra tinh chat BST
int isBSTUtil(Node* node, int min, int max) {
    if (node == NULL) {
        return 1;
    }
    if (node->data <= min || node->data >= max) {
        return 0;
    }
    return isBSTUtil(node->left, min, node->data) && isBSTUtil(node->right, node->data, max);
}

int isBST(Node* root) {
    return isBSTUtil(root, -2147483648, 2147483647);
}

int main(){
	Node* tree = NULL;
	tree = insertNode(tree,4);
	tree = insertNode(tree,3);
	tree = insertNode(tree,6);
	tree = insertNode(tree,2);
	tree = insertNode(tree,5);
	
	if (isBST(tree)) {
        printf("\nCay la mot Binary Search Tree\n");
    } else {
        printf("\nCay khong phai la mot Binary Search Tree\n");
    }

	return 0;	
}

