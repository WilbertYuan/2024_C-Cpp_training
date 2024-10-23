#include <stdio.h>
#include <stdlib.h>
// ���������ṹ�嶨��
typedef struct btnode {
	char element;          // ����Ԫ��
	struct btnode* lChild; // ����ָ��
	struct btnode* rChild; // �Һ���ָ��
} BTNode;

// �������ṹ�嶨��
typedef struct binarytree {
	BTNode* root;         // ָ�������ָ��
} BinaryTree;

BTNode* NewNode(char x, BTNode* ln, BTNode* rn) {
	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
	if (!p) return NULL; // �ڴ����ʧ��
	p->element = x;
	p->lChild = ln;
	p->rChild = rn;
	return p;
}

// ����
void Create(BinaryTree* bt) {
	bt->root = NULL; // ��ʼ�������Ϊ��
}

// �������
void PreOrder(BTNode* t) {
	if (!t) return;
	printf("%c ", t->element); // ���ʸ����
	PreOrder(t->lChild);       // �������������
	PreOrder(t->rChild);       // �������������
}

void PreOrderTree(BinaryTree* bt) {
	PreOrder(bt->root);
}

// ����������
int CountNodes(BTNode* t) {
	if (!t) return 0;
	return 1 + CountNodes(t->lChild) + CountNodes(t->rChild); // �ݹ����
}

// ����Ҷ������
int CountLeafNodes(BTNode* t) {
	if (!t) return 0;
	if (!t->lChild && !t->rChild) return 1; // Ҷ���
	return CountLeafNodes(t->lChild) + CountLeafNodes(t->rChild); // �ݹ����
}

// �������ĸ߶�
int TreeHeight(BTNode* t) {
	if (!t) return 0;
	int leftHeight = TreeHeight(t->lChild);
	int rightHeight = TreeHeight(t->rChild);
	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; // ���ظ߶�
}

// ��������������������
void SwapSubtrees(BTNode* t) {
	if (!t) return;
	BTNode* temp = t->lChild;
	t->lChild = t->rChild;
	t->rChild = temp;
	SwapSubtrees(t->lChild);
	SwapSubtrees(t->rChild);
}


int main() {
	BinaryTree bt;
	Create(&bt);
	BTNode* a = NewNode('A', NULL, NULL);
	BTNode* b = NewNode('B', NULL, NULL);
	BTNode* c = NewNode('C', NULL, NULL);
	BTNode* d = NewNode('D', NULL, NULL);
	BTNode* e = NewNode('E', NULL, NULL);

	bt.root = NewNode('F', a, b);
	a->lChild = c;
	a->rChild = d;
	b->rChild = e;

	printf("�������: ");
	PreOrderTree(&bt);
	printf("\n�������: %d\n", CountNodes(bt.root));
	printf("Ҷ������: %d\n", CountLeafNodes(bt.root));
	printf("���ĸ߶�: %d\n", TreeHeight(bt.root));

	SwapSubtrees(bt.root);
	printf("������������������: ");
	PreOrderTree(&bt);
	printf("\n");
	return 0;
}

