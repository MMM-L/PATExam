#include<iostream>
using namespace std;

// ƽ��������ṹ��
typedef struct TreeNode* AVLTree;
struct TreeNode {
  int data;
  int height;
  AVLTree left;
  AVLTree right;
};

AVLTree Insert(AVLTree root, int x);
int GetHeight(AVLTree root);
int HeightMax(int height1, int height2);
AVLTree Lrot(AVLTree root);
AVLTree Rrot(AVLTree root);
AVLTree LRrot(AVLTree root);
AVLTree RLrot(AVLTree root);

int main() {
  AVLTree root{};
  int N{}, temp{};
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    root = Insert(root, temp);
  }
  if (root) {
    cout << root->data;
  }
  return 0;
}

// AVL�Ĳ��룬��Ҫ���ϵĵ������Ľṹ
// ������ڵݹ��˼�룬��Ҫ�ú����(==+-2����ط�)
AVLTree Insert(AVLTree root, int x) {
  if (!root) {
    root = new struct TreeNode;
    root->data = x;
    root->height = 1;
    root->left = NULL;
    root->right = NULL;
  } else {
    if (x > root->data) {  // ����������
      root->right = Insert(root->right, x);
      // ��Ҫ����ΪRR��RL�ͣ���������ת��������ת
      if (GetHeight(root->left) - GetHeight(root->right) == -2) {
        if (x > root->right->data) {
          root = Lrot(root);
        } else {
          root = RLrot(root);
        }
      }
    } else if (x < root->data) {  // ����������
      root->left = Insert(root->left, x);
      // ��Ҫ����ΪLL��LR�ͣ���������ת��������ת
      if (GetHeight(root->left) - GetHeight(root->right) == 2) {
        if (x < root->left->data) {
          root = Rrot(root);
        } else {
          root = LRrot(root);
        }
      }
    }
  }
  root->height = HeightMax(GetHeight(root->left), GetHeight(root->right)) + 1;
  return root;
}

// �����ĸ߶�
int GetHeight(AVLTree root) {
  if (!root) {  // ��Ϊ�գ��߶�Ϊ0
    return 0;
  } else {  // ����height��Ͳ���Ҫ�ݹ���
    return root->height;
  }
}

// ȡheight1��height2�еĽϴ�ֵ
int HeightMax(int height1, int height2) {
  return height1 > height2 ? height1 : height2;
}

// ����
AVLTree Lrot(AVLTree root) {
  AVLTree temp = root->right;
  root->right = temp->left;
  temp->left = root;
  // �ǵø�������
  root->height = HeightMax(GetHeight(root->left), GetHeight(root->right)) + 1;
  temp->height = HeightMax(GetHeight(temp->left), GetHeight(temp->right)) + 1;
  return temp;
}

// ����
AVLTree Rrot(AVLTree root) {
  AVLTree temp = root->left;
  root->left = temp->right;
  temp->right = root;
  root->height = HeightMax(GetHeight(root->left), GetHeight(root->right)) + 1;
  temp->height = HeightMax(GetHeight(temp->left), GetHeight(temp->right)) + 1;
  return temp;
}

// ������
AVLTree LRrot(AVLTree root) {
  // ������
  root->left = Lrot(root->left);
  // ������
  root = Rrot(root);
  return root;
}

// ������
AVLTree RLrot(AVLTree root) {
  // ������
  root->right = Rrot(root->right);
  // ������
  root = Lrot(root);
  return root;
}
