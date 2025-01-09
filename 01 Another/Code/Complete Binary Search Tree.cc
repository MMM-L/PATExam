// ��Ŀ��ַ��
// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805407749357568&page=0
//
#include <iostream>
#include <algorithm>
using namespace std;

int N{};          // �ڵ�ĸ���
int in[1001]{};   // ���������ֵ
int level[1001];  // ���������ֵ
int in_dx = 0;    // ��������Ľڵ�ָʾ

void InOrder(int root);  // �������

int main() {
  
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> in[i];
  }
  sort(in, in + N);  // ��ȫ��������������������ǰ�˳������õ�
  InOrder(0);
  for (int i = 0; i < N; ++i) {
    if (i != 0) {
      cout << ' ';
    }
    cout << level[i] ;
  }
  return 0;
}

void InOrder(int root) { 
  if (root >= N) {
    return;
  }
  InOrder(2 * root + 1);  // left root;
  level[root] = in[in_dx++];
  InOrder(2 * root + 2);  // right root;
}



