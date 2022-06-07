//이진탐색트리
#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

//노드 구조체
typedef struct AVLNode {
	int key;
	struct AVLNode* left, * right;
}AVLNode;

//노드 생성 함수
AVLNode* createNode(int key) {
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = node->right = NULL; //생성되는 노드는 단말노드이다

	return node;
}

//트리의 높이 구하는 함수
int getHeight(AVLNode* node) {
	int height = 0;
	if (node != NULL) {
		height = 1 + MAX(getHeight(node->left), getHeight(node->right));
	}
	return height;
}

//균형인수 함수
int getBalance(AVLNode* node) {
	if (node == NULL) {
		return 0;
	}

	else {
		//왼쪽서브트리높이-오른쪽서브트리높이
		return getHeight(node->left) - getHeight(node->right);
	}
}

//부모노드를 오른쪽으로 회전하는 함수
AVLNode* rotateRight(AVLNode* p) {
	AVLNode* c = p->left;
	p->left = c->right;
	c->right = p;
	return c;
}

//부모노드를 왼쪽으로 회전하는 함수
AVLNode* rotateLeft(AVLNode* p) {
	AVLNode* c = p->right;
	p->right = c->left;
	c->left = p;
	return c;
}

//노드 삽입 함수
AVLNode* insert(AVLNode* node, int key) {
	if (node == NULL) {
		return createNode(key);
	}

	if (key < node->key) {
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}
	else {
		return node;
	}

	int balance = getBalance(node); //균형인수

	if (balance > 1 && key < node->left->key) { //LL
		return rotateRight(node);
	}
	if (balance > 1 && key > node->left->key) { //LR
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}
	if (balance < -1 && key < node->right->key) { //RL
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}
	if (balance <-1 && key > node->right->key) { //RR
		return rotateLeft(node);
	}

	return node;
}

//전위 순회 함수
void preOrder(AVLNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

//중위 순회 함수
void inOrder(AVLNode* root) {
	if (root != NULL) {
		inOrder(root->left);
		printf("[%d] ", root->key);
		inOrder(root->right);
	}
}

//이진 탐색 함수
AVLNode* searchNode(AVLNode* node, int key) {

	if (node == NULL) { //탐색에 실패하는 경우
		return NULL;
	}


	if (key == node->key) { //탐색에 성공하는 경우
		return node;
	}
	else if (key > node->key) { //오른쪽 서브트리로 이동
		return searchNode(node->right, key);
	}
	else { //왼쪽 서브트리로 이동
		return searchNode(node->left, key);
	}
}

int main(void) {
	AVLNode* root = NULL;

	//LL type AVL, 전위순회
	root = insert(root, 35); inOrder(root); printf("\n");
	root = insert(root, 25); inOrder(root); printf("\n");
	root = insert(root, 13); inOrder(root); printf("\n");
	root = insert(root, 40); inOrder(root); printf("\n");
	root = insert(root, 45); inOrder(root); printf("\n");
	root = insert(root, 30); inOrder(root); printf("\n");

}