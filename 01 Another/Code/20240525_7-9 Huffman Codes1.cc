// Huffman Codes
// https://pintia.cn/problem-sets/16/exam/problems/type/7?problemSetProblemId=671&page=0
// 
// ==================================
#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cstdlib>
#include<map>
#include<string>
#include<iostream>

#define HeapCapacity 64
#define MinData 0

// �������ֽṹ�������������ʽ���о������ö����
// ������ʹ��ָ������ֱ�Ӿ͸ı��Ӧ��ֵ�������ٴ����ã�
// �������ں������ݲ�����ʱ������õ�
typedef struct TreeNode* HuffmanTree;
typedef struct Heap* MinHeap;

struct Heap {
  HuffmanTree* data;
  int size;  // �ѵĵ�ǰ��С
};

struct TreeNode {
  int weight;  // Ƶ��
  HuffmanTree left;
  HuffmanTree right;
};
using namespace std;

map<char, int> mapp;

//
MinHeap InitHeap(int n);
MinHeap CreatHeap();
HuffmanTree CreateHuffmanTree();
void AdjustMinHeap(MinHeap H);
void SortMinHeap(MinHeap H, int i);
HuffmanTree DeleteMinHeap(MinHeap H);
void InseretMinHeap(MinHeap H, HuffmanTree Huff);
int WeightPlantLength(HuffmanTree Huff, int depth);
HuffmanTree Huffman(MinHeap H);
void SubmitJudge(int n, int codeLen);

void SubmitJudge(int n, int codeLen) {
  HuffmanTree Huff = CreateHuffmanTree();
  HuffmanTree pre;
  int counter = 1;
  bool flag = true;  // �Ƿ���ǰ׺����жϱ�־
  char ch;
  string code;

  // ���ݱ��뷽ʽ������һ��Huffman Tree
  for (int i = 0; i < n; ++i) {
    getchar();
    scanf("%c", &ch);
    cin >> code;
    pre = Huff;  // ÿ�ζ���Huffman tree��ʼ�ж�
    // ��ʼ����Huffman Tree
    for (int j = 0; j < code.size(); ++j) {
      if (code[j] == '0') {  // �����ǰ����Ϊ0�����֧
        if (pre->left == NULL) {
          pre->left = CreateHuffmanTree();
          ++counter;
        }
        if (pre->weight != 0) {  // ��Ҳ�ǻ����ǰ׺����
          flag = false;
        }
        pre = pre->left;
      } else if (code[j] == '1') {  // �����ǰ����Ϊ1���ҷ�֧
        if (pre->right == NULL) {
          pre->right = CreateHuffmanTree();
          ++counter;
        }
        if (pre->weight != 0) {  // ��Ҳ�ǻ����ǰ׺����
          flag = false;
        }
        pre = pre->right;
      }
    }
    if (pre->left || pre->right) {  // ��Ҳ�ǻ����ǰ׺����
      flag = false;
    }
    pre->weight = mapp[ch];  // ȡ���ַ�����Ӧ���ֵ�Ƶ��
  }

  // �ж��Ƿ�����Huffman codes��Ҫ��
  if ((counter == 2*n-1) && flag && (WeightPlantLength(Huff, 0) == codeLen)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

// ����Huffman codes�ĳ���
int WeightPlantLength(HuffmanTree Huff, int depth) {
  if ((Huff->left == NULL) && (Huff->right == NULL)) {
    return depth * Huff->weight;
  } else {  // Huffman����һ��������������Ҫ�����������ӽ�㣬Ҫ������0���ӽ�㣩
    return (WeightPlantLength(Huff->left, depth + 1) +
            WeightPlantLength(Huff->right, depth + 1));
  }
}

// ����HuffmanTree
HuffmanTree Huffman(MinHeap H) {
  int times = H->size;
  HuffmanTree Huff;
  for (int i = 1; i < times; ++i) {  // �� times-1�ε����
    Huff = CreateHuffmanTree();
    Huff->left = DeleteMinHeap(H);
    Huff->right = DeleteMinHeap(H);
    Huff->weight = Huff->left->weight + Huff->right->weight;
    InseretMinHeap(H, Huff);
  }
  Huff = DeleteMinHeap(H);  // ȡ�������õ�Huffman tree
  return Huff;
}

// ɾ����С��
HuffmanTree DeleteMinHeap(MinHeap H) {
  int parent{}, child{};
  HuffmanTree huff_first = H->data[1];
  HuffmanTree huff_end = H->data[H->size];
  --H->size;  // ɾ��һ��

  // ֱ�ӿ�ʼ����MinHeap
  for (parent = 1; 2 * parent <= H->size; parent = child) {
    // �����Ҷ���������С��
    child = 2 * parent;
    if ((child != H->size) &&
        (H->data[child + 1]->weight < H->data[child]->weight)) {
      ++child;
    }
    // ���û����С���ˣ�����ѭ��������
    if (huff_end->weight <= H->data[child]->weight) {
      break;
    }
    // ����ͰѶ��ӽ��������
    H->data[parent] = H->data[child];
  }
  H->data[parent] = huff_end;
  return huff_first;
}

// ������С��
// ��������ĸ�ʽ���Ǻܼ��
void InseretMinHeap(MinHeap H, HuffmanTree Huff) {
  int i = ++H->size;
  // �ڱ�������������˰ɣ�
  for (; Huff->weight < H->data[i / 2]->weight; i /= 2) {  // �����i/2�����ǻ����0��������֮ǰ�Ǹ��ڱ���
    H->data[i] = H->data[i / 2];
  }
  H->data[i] = Huff;
}

// ��ʼ����
MinHeap InitHeap(int n) {
  MinHeap H = CreatHeap();
  HuffmanTree Huff{};
  char c_temp{};
  int f_temp{};
  for (int i = 0; i < n; ++i) {
    getchar();  // ��������ΪʲôҪһ��getchar������(���뻻�з����Ϳո�)
    scanf("%c %d", &c_temp, &f_temp);  // ��������ͼ�¼�ķ�ʽ���ǵ�һ�ο���
    mapp.insert(pair<char, int>(c_temp, f_temp));
    Huff = CreateHuffmanTree();
    Huff->weight = f_temp;
    H->data[++H->size] = Huff;  // ע�����ﻹ��һ��H->size
  }
  AdjustMinHeap(H);
  return H;
}

// ����Ϊ��С��
void AdjustMinHeap(MinHeap H) {
  // �ӵ�һ���к��ӽ��Ľ�㿪ʼ���е�����(��ȫ���������洢�������е�һ�㼼��)
  for (int i = H->size / 2; i > 0; --i) {
    SortMinHeap(H, i);
  }
}

// ��������С��
void SortMinHeap(MinHeap H, int i) {
  int parent{}, child {};
  HuffmanTree Huff = H->data[i];  // ��ǰ���Ĺ�������
  for (parent = i; parent * 2 <= H->size; parent = child) {
    child = 2 * parent; // ���ӽ��
    // �������ӽ����ѡȡ��С��
    if ((child != H->size) && (H->data[child + 1]->weight < H->data[child]->weight)) {
      ++child;
    }
    if (H->data[parent]->weight <= H->data[child]->weight) {
      break;
    }
    H->data[parent] = H->data[child];  // parentһ����Ҫ��child�����ģ�ǰ�治����һ��break��
  }
  H->data[parent] = Huff;  // ��һ��������ô��������
}

// ����
MinHeap CreatHeap() {
  MinHeap H;
  H = (MinHeap) malloc(sizeof(struct Heap));
  // H->data = (HuffmanTree*)malloc(sizeof(struct TreeNode) * HeapCapacity);  // �����ַ�ķ���û������
  H->data = (HuffmanTree*)malloc(sizeof(HuffmanTree) * HeapCapacity);  // �Ҿ���Ӧ����������
  H->size = 0;
  HuffmanTree Huff = CreateHuffmanTree();  // �����ڱ������������ǣ�
  H->data[0] = Huff;
  return H;
}

// ������������
HuffmanTree CreateHuffmanTree() {
  HuffmanTree Huff;
  Huff = (HuffmanTree)malloc(sizeof(struct TreeNode));
  Huff->left = NULL;
  Huff->right = NULL;
  Huff->weight = MinData;  // ��ʼ��Ƶ����С��
  return Huff;
}

//
int main(int argc, char* argv[]) {
  int n{}, m{};  // �����ַ���n��ѧ������m
  scanf("%d", &n);

  // ��ʼ����С��
  MinHeap H = InitHeap(n);

  // ����Huffman Tree
  HuffmanTree Huff = Huffman(H);

  // ����Huffman����ĳ���
  // ע��������0����
  int codeLen = WeightPlantLength(Huff, 0);

  // �ж�m��ѧ������ı��뷽ʽ
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    SubmitJudge(n, codeLen);
  }
  return 0;
}

