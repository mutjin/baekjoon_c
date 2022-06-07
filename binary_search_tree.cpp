////����Ž��Ʈ��
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX(a,b) (a>b?a:b)
//
////��� ����ü
//typedef struct TreeNode {
//	int key;
//	struct TreeNode* left, * right;
//}TreeNode;
//
////��� ���� �Լ�
//TreeNode* createNode(int key) {
//	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
//	node->key = key;
//	node->left = node->right = NULL; //�����Ǵ� ���� �ܸ�����̴�
//
//	return node;
//}
//
////��� ���� �Լ�
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
////���� ��ȸ �Լ�
//void preOrder(TreeNode* root) {
//	if (root != NULL) {
//		printf("[%d] ", root->key);
//		preOrder(root->left);
//		preOrder(root->right);
//	}
//}
//
////���� ��ȸ �Լ�
//void inOrder(TreeNode* root) {
//	if (root != NULL) {
//		inOrder(root->left);
//		printf("[%d] ", root->key);
//		inOrder(root->right);
//	}
//}
//
////���� Ž�� �Լ�
//TreeNode* searchNode(TreeNode* node, int key) {
//	
//	if (node == NULL) { //Ž���� �����ϴ� ���
//		return NULL;
//	}
//
//
//	if (key == node->key) { //Ž���� �����ϴ� ���
//		return node;
//	}
//	else if (key > node->key) { //������ ����Ʈ���� �̵�
//		return searchNode(node->right, key);
//	}
//	else { //���� ����Ʈ���� �̵�
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
//	//inOrder(root); printf("\n"); getchar(); //������ȸ
//
//	root = insert(root, 22);
//	root = insert(root, 17);
//	root = insert(root, 55);
//	//inOrder(root); printf("\n"); getchar(); //������ȸ
//
//	root = insert(root, 30);
//	root = insert(root, 34);
//	root = insert(root, 65);
//	inOrder(root); printf("\n"); getchar(); //������ȸ
//
//	//����Ž��
//	if (searchNode(root, 30)) {
//		printf("found\n");
//	}
//	else {
//		printf("not found\n");
//	}
//}