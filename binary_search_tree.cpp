////이진탐색트리
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX(a,b) (a>b?a:b)
//
////노드 구조체
//typedef struct TreeNode {
//	int key;
//	struct TreeNode* left, * right;
//}TreeNode;
//
////노드 생성 함수
//TreeNode* createNode(int key) {
//	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
//	node->key = key;
//	node->left = node->right = NULL; //생성되는 노드는 단말노드이다
//
//	return node;
//}
//
////노드 삽입 함수
//TreeNode* insert(TreeNode* node, int key) {
//	if (node == NULL) {
//		return createNode(key);
//	}
//
//	if (key < node->key) {
//		node->left = insert(node->left, key);
//	}
//	else if (key > node->key) {
//		node->right = insert(node->right, key);
//	}
//	else {
//		return node;
//	}
//	return node;
//}
//
////전위 순회 함수
//void preOrder(TreeNode* root) {
//	if (root != NULL) {
//		printf("[%d] ", root->key);
//		preOrder(root->left);
//		preOrder(root->right);
//	}
//}
//
////중위 순회 함수
//void inOrder(TreeNode* root) {
//	if (root != NULL) {
//		inOrder(root->left);
//		printf("[%d] ", root->key);
//		inOrder(root->right);
//	}
//}
//
////이진 탐색 함수
//TreeNode* searchNode(TreeNode* node, int key) {
//	
//	if (node == NULL) { //탐색에 실패하는 경우
//		return NULL;
//	}
//
//
//	if (key == node->key) { //탐색에 성공하는 경우
//		return node;
//	}
//	else if (key > node->key) { //오른쪽 서브트리로 이동
//		return searchNode(node->right, key);
//	}
//	else { //왼쪽 서브트리로 이동
//		return searchNode(node->left, key);
//	}
//}
//
//int main(void) {
//	TreeNode* root = NULL;
//
//	root = insert(root, 35);
//	root = insert(root, 68);
//	root = insert(root, 35);
//	//inOrder(root); printf("\n"); getchar(); //전위순회
//
//	root = insert(root, 22);
//	root = insert(root, 17);
//	root = insert(root, 55);
//	//inOrder(root); printf("\n"); getchar(); //전위순회
//
//	root = insert(root, 30);
//	root = insert(root, 34);
//	root = insert(root, 65);
//	inOrder(root); printf("\n"); getchar(); //전위순회
//
//	//이진탐색
//	if (searchNode(root, 30)) {
//		printf("found\n");
//	}
//	else {
//		printf("not found\n");
//	}
//}