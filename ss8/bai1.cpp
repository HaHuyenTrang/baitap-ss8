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




//	duyet cay theo pp tien thu tu
void preorderTraversal(Node* node){
	if(node != NULL){
		printf("%d\t", node->data);
		preorderTraversal(node->left);
		preorderTraversal(node->right);
	}
}

//	trung thu tu
void inOrderNode(Node* node){
	if( node!= NULL){
		inOrderNode(node->left);
		printf("%d\t", node->data);
		inOrderNode(node->right);
	}
} 
// 	hau thu tu
void postOrderNode(Node* node){
	if( node!= NULL){
		postOrderNode(node->left);
		postOrderNode(node->right);
		printf("%d\t", node->data);
	}
} 



int main(){
	Node* tree = NULL;
	tree = insertNode(tree,4);
	tree = insertNode(tree,3);
	tree = insertNode(tree,6);
	tree = insertNode(tree,2);
	tree = insertNode(tree,5);
	printf("\n");
	printf("tien thu tu: ");
	preorderTraversal(tree);
	printf("\n");
	printf("trung thu tu: ");
	inOrderNode(tree);
	printf("\n");
	printf("hau thu tu: ");
	postOrderNode(tree);
	return 0;	
}

