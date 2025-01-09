// https://pintia.cn/problem-sets/1603283867296088064/exam/problems/1603283867392557065
// �ο����룺https://blog.csdn.net/liyuanyue2017/article/details/83539009

#include<iostream>
#include<queue>
using namespace std;

// ���Ľ��
struct TreeNode {
  int data;
  int left;
  int right;
};

int main() {
  int N{}, root{}, flag{};
  char l1{}, l2{};
  TreeNode temp{};
  TreeNode Tr[10]{};
  queue<struct TreeNode> q;  // ����
  // �����������н��
  cin >> N;
  if (!N) {  // ���Ϊ����
    root = -1;
    return 0;
  }
  for (int i = 0; i < N; i++) {
    Tr[i].data = i;
    cin >> l1 >> l2;  // cin���﷨Ҫ�и���̵����
    if (l1 == '-') {
      Tr[i].left = -1;
    }
    else {
      Tr[i].left = l1 - '0';
      root -= Tr[i].left;
    }
    if (l2 == '-') {
      Tr[i].right = -1;
    }
    else {
      Tr[i].right = l2 - '0';
      root -= Tr[i].right;
    }
    root += i;  // û�б���ȥ�ľ��Ǹ����
  }

  // ������������ж�Ҷ�ӽ��
  // ���������Ҫ�õ����е�֪ʶ��
  q.push(Tr[root]);
  while (!q.empty()) {
    temp = q.front();
    q.pop();
    if ((temp.left == -1) && (temp.right == -1)) {
      if (flag) {
        // �������ո��ǵ�һ�������˹�
        cout << ' ';
      } else {
        flag = 1;
      }
      cout << temp.data;
    }
    if (temp.left != -1) {
      q.push(Tr[temp.left]);
    }
    if (temp.right != -1) {
      q.push(Tr[temp.right]);
    }
  }
  return 0;
}
