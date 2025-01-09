#include <iostream>
using namespace std;

#define MAX_TREE 10
#define NONE -1
typedef char ElementType;
typedef int Tree;

// ��̬�������ʽ
struct TreeNode {
  ElementType element;
  Tree left;
  Tree right;
};

TreeNode tree1[MAX_TREE];
TreeNode tree2[MAX_TREE];

Tree BuildTree(TreeNode tree[]);
bool IsOmorphic(Tree r1, Tree r2);

int main() {
  Tree r1, r2;
  // ����������
  r1 = BuildTree(tree1);
  r2 = BuildTree(tree2);
  if (IsOmorphic(r1, r2)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

// ����һ����
Tree BuildTree(TreeNode tree[]) {
  int n;
  int check[MAX_TREE] = {0};
  char cl, cr;
  Tree root = NONE;
  cin >> n;
  if (!n) return root;
  for (int i = 0; i < n; i++) {
    cin >> tree[i].element >> cl >> cr;
    if (cl == '-') {
      tree[i].left = NONE;
    } else {
      tree[i].left = cl - '0';
      check[tree[i].left] = 1;
    }
    if (cr == '-') {
      tree[i].right = NONE;
    } else {
      tree[i].right = cr - '0';
      check[tree[i].right] = 1;
    }
  }
  // �ĸ����û��û�������ӣ��ĸ����Ǹ����
  for (int i = 0; i < n; i++) {
    if (!check[i]) {
      root = i;
      break;
    }
  }
  // ���ظ����
  return root;
}

// �ж��������Ƿ�ͬ��
// ��������˵ݹ��˼��ǳ�ֵ��ѧϰ
bool IsOmorphic(Tree r1, Tree r2) {
  // ��������Ϊ��
  if (r1 == NONE && r2 == NONE) {
    return true;
  }
  // ���һ����Ϊ�գ�һ������Ϊ��
  if (((r1 == NONE) && (r2 != NONE)) || ((r1 != NONE) && (r2 == NONE))) {
    return false;
  }
  // �����������յĻ�
  // �жϸ�����ֵ�Ƿ���ͬ
  if (tree1[r1].element != tree2[r2].element) {
    return false;
  }
  // ���ڸ�����ж����
  // �����������Ϊ�գ��ж�������
  if (tree1[r1].left == NONE && tree2[r2].left == NONE) {
    return IsOmorphic(tree1[r1].right, tree2[r2].right);
  }
  // �������������Ϊ�գ�������ж���ȥ
  if ((tree1[r1].left != NONE && tree2[r2].left != NONE) &&
      (tree1[tree1[r1].left].element == tree2[tree2[r2].left].element)) {
    return IsOmorphic(tree1[r1].left, tree2[r2].left) && 
           IsOmorphic(tree1[r1].right, tree2[r2].right);
  } else {  // ������Ҫ�����������½���
    return IsOmorphic(tree1[r1].right, tree2[r2].left) &&
           IsOmorphic(tree1[r1].left, tree2[r2].right);
  }
 }
