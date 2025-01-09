#include<iostream>
#include<algorithm>

using namespace std;

struct Tree {
  int K1;
  int K2;
  int left_tree;
  int right_tree;
} tree[1002];
bool root_flag[1002];
bool ans_flag = true;


// �ж��Ƿ��ǵѿ�����
void JudgeTree(int root, int min_K1, int max_K1) {
  if (root == -1) {
    return;
  }
  int K1 = tree[root].K1;
  int K2 = tree[root].K2;
  int left_tree = tree[root].left_tree;
  int right_tree = tree[root].right_tree;

  // ��ʼ�ж�
  if (K1 < min_K1 || K1 > max_K1) {
    ans_flag = false;
    return;
  }

  if (left_tree != -1) {
    if (K2 > tree[left_tree].K2) {
      ans_flag = false;
    }
  }
  
  if (right_tree != -1) {
    if (K2 > tree[right_tree].K2) {
      ans_flag = false;
    }
  }

  JudgeTree(left_tree, min_K1, K1); // �ж�������
  JudgeTree(right_tree, K1, max_K1); // �ж�������
}

int main() {
  int N{}, root_num{};
  cin >> N;
  fill(root_flag, root_flag + N, true);

  // ��������ԡ�����
  for (int i = 0; i < N; ++i) {
    cin >> tree[i].K1 >> tree[i].K2 >> tree[i].left_tree >> tree[i].right_tree;
    if (tree[i].left_tree != -1) {
      root_flag[tree[i].left_tree] = false;  // ��Ϊ���ӽ�㣬�ض����Ǹ��ڵ�
    }
    if (tree[i].right_tree != -1) {
      root_flag[tree[i].right_tree] = false;
    }
  }

  // Ѱ�����ĸ��ڵ�
  for (int i = 0; i < N; ++i) {
    if (root_flag[i]) {
      root_num = i;
    }
  }

  // �ж��Ƿ��ǵѿ�����
  JudgeTree(root_num, INT32_MIN, INT32_MAX);

  if (ans_flag) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}
