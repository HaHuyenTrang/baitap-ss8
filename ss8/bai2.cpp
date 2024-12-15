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

// in cac dinh lop 2
void printLevel2Nodes(Node* root){
    if (root == NULL) {
        return;
    }

    // nut goc kh cos con, khong co dinh lop 2
    if (root->left == NULL && root->right == NULL) {
        return;
    }

    // duyet con trai qua con phai
    if (root->left != NULL) {
        if (root->left->left != NULL) {
            printf("%d ", root->left->left->data);
        }
        if (root->left->right != NULL) {
            printf("%d ", root->left->right->data);
        }
    }

    if (root->right != NULL) {
        if (root->right->left != NULL) {
            printf("%d ", root->right->left->data);
        }
        if (root->right->right != NULL) {
            printf("%d ", root->right->right->data);
        }
    }
}


int main(){
	Node* tree = NULL;
	tree = insertNode(tree,4);
	tree = insertNode(tree,3);
	tree = insertNode(tree,6);
	tree = insertNode(tree,2);
	tree = insertNode(tree,5);
	
	
	printf("Cac dinh o lop 2 la: ");
    printLevel2Nodes(tree);
	return 0;	
}

