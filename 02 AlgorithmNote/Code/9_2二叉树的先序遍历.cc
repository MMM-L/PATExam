#include<iostream>
using namespace std;

const int MaxN = 50;

// ������Ķ���
// ���ǵ���Ŀ�����룬�����ýṹ����������ʾ�������
// ����һ����ԣ����������������ʽ���������ͽ�����صĲ�����
struct TreeNode {
  int LtreeNode;
  int RtreeNode;
}Tree[MaxN];


// ���������ֱ�Ӿ����
// �����治���ж���Ŀո�
void PreorderTraversal(int root) {
  static int flag{};
  ++flag;
  if (root != -1) {
    if (flag != 1) {
      cout << ' ';
    }
    cout << root;
    PreorderTraversal(Tree[root].LtreeNode);
    PreorderTraversal(Tree[root].RtreeNode);
  }
}


int main() { 
  int n{}, root{};
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int l_temp{}, r_temp{};

    // ���뵱ǰ�Ľڵ�����
    cin >> l_temp >> r_temp;
    Tree[i].LtreeNode = l_temp;
    Tree[i].RtreeNode = r_temp;

    // ��һ�����ж���һ���Ǹ��ڵ�
    // ���������Ŀ�������˸��ڵ�Ϊ0��ѽ
    root += i;
    if (l_temp != -1) {
      root -= l_temp;
    }
    if (r_temp != -1) {
      root -= r_temp;
    }
  }
  PreorderTraversal(root);
  return 0;
}
