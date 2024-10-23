#include <stdio.h>
#include <stdlib.h>

// �����������ṹ�嶨��
typedef struct hfmNode {
    int weight;                // Ȩ��
    struct hfmNode* left;      // ����
    struct hfmNode* right;     // �Һ���
} HfmNode;

// ���������������
HfmNode* CreateHfmNode(int weight) {
    HfmNode* node = (HfmNode*)malloc(sizeof(HfmNode));
    node->weight = weight;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ��������������ıȽϺ������������ȶ��У�
int Compare(const void* a, const void* b) {
    return ((HfmNode*)a)->weight - ((HfmNode*)b)->weight;
}

// ������������
HfmNode* CreateHuffmanTree(int weights[], int n) {
    HfmNode** nodes = (HfmNode**)malloc(n * sizeof(HfmNode*));

    // ����Ҷ�ӽ��
    for (int i = 0; i < n; i++) {
        nodes[i] = CreateHfmNode(weights[i]);
    }

    // ������������
    while (n > 1) {
        // ����
        qsort(nodes, n, sizeof(HfmNode*), Compare);

        // ȡ��Ȩ����С���������
        HfmNode* left = nodes[0];
        HfmNode* right = nodes[1];

        // �����½�㣬Ȩ��Ϊ����������Ȩ��֮��
        HfmNode* parent = CreateHfmNode(left->weight + right->weight);
        parent->left = left;
        parent->right = right;

        // �滻ԭ�н��
        nodes[0] = parent;
        for (int i = 1; i < n - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        n--;
    }

    HfmNode* root = nodes[0];
    free(nodes);
    return root;
}

// ��ӡ����������
void PrintHuffmanCodes(HfmNode* root, char* code, int length) {
    if (!root) return;

    // �����Ҷ�ӽ�㣬��ӡ����
    if (!root->left && !root->right) {
        code[length] = '\0'; // �����ַ���
        printf("Ȩ�� %d: %s\n", root->weight, code);
    }

    // ������������������
    code[length] = '0'; // ����������
    PrintHuffmanCodes(root->left, code, length + 1);

    code[length] = '1'; // ����������
    PrintHuffmanCodes(root->right, code, length + 1);
}

// ������
int main() {
    int weights[] = { 5, 9, 12, 13, 16, 45 }; // ���ַ���Ȩ��
    int n = sizeof(weights) / sizeof(weights[0]);

    // ������������
    HfmNode* root = CreateHuffmanTree(weights, n);

    // ��ӡ����������
    char code[100]; // �洢����
    printf("����������:\n");
    PrintHuffmanCodes(root, code, 0);

    // �ͷ��ڴ棨�ԣ�

    return 0;
}
