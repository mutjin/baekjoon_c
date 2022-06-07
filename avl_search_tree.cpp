//����Ž��Ʈ��
#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

//��� ����ü
typedef struct AVLNode {
	int key;
	struct AVLNode* left, * right;
}AVLNode;

//��� ���� �Լ�
AVLNode* createNode(int key) {
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = node->right = NULL; //�����Ǵ� ���� �ܸ�����̴�

	return node;
}

//Ʈ���� ���� ���ϴ� �Լ�
int getHeight(AVLNode* node) {
	int height = 0;
	if (node != NULL) {
		height = 1 + MAX(getHeight(node->left), getHeight(node->right));
	}
	return height;
}

//�����μ� �Լ�
int getBalance(AVLNode* node) {
	if (node == NULL) {
		return 0;
	}

	else {
		//���ʼ���Ʈ������-�����ʼ���Ʈ������
		return getHeight(node->left) - getHeight(node->right);
	}
}

//�θ��带 ���������� ȸ���ϴ� �Լ�
AVLNode* rotateRight(AVLNode* p) {
	AVLNode* c = p->left;
	p->left = c->right;
	c->right = p;
	return c;
}

//�θ��带 �������� ȸ���ϴ� �Լ�
AVLNode* rotateLeft(AVLNode* p) {
	AVLNode* c = p->right;
	p->right = c->left;
	c->left = p;
	return c;
}

//��� ���� �Լ�
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

	int balance = getBalance(node); //�����μ�

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

//���� ��ȸ �Լ�
void preOrder(AVLNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

//���� ��ȸ �Լ�
void inOrder(AVLNode* root) {
	if (root != NULL) {
		inOrder(root->left);
		printf("[%d] ", root->key);
		inOrder(root->right);
	}
}

//���� Ž�� �Լ�
AVLNode* searchNode(AVLNode* node, int key) {

	if (node == NULL) { //Ž���� �����ϴ� ���
		return NULL;
	}


	if (key == node->key) { //Ž���� �����ϴ� ���
		return node;
	}
	else if (key > node->key) { //������ ����Ʈ���� �̵�
		return searchNode(node->right, key);
	}
	else { //���� ����Ʈ���� �̵�
		return searchNode(node->left, key);
	}
}

int main(void) {
	AVLNode* root = NULL;

	//LL type AVL, ������ȸ
	root = insert(root, 35); inOrder(root); printf("\n");
	root = insert(root, 25); inOrder(root); printf("\n");
	root = insert(root, 13); inOrder(root); printf("\n");
	root = insert(root, 40); inOrder(root); printf("\n");
	root = insert(root, 45); inOrder(root); printf("\n");
	root = insert(root, 30); inOrder(root); printf("\n");

}