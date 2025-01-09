// ��С������_Prime�㷨��������Dijkstra�㷨
// Ҫ������ͼ��ͨ���ҵ�һ�����ܹ��������еĶ��㣬
// ������ϵ�Ȩֵ֮��Ҫ����С�ģ������Ľṹ��Ψһ��
// ����СȨֵ��Ψһ�ġ�
#include <iostream>
#include <algorithm>
using namespace std;

const int Inf = 0x3FFFFFFF;  // �Զ��������
const int MaxVet = 100;      // ��ඥ����
int n{};                     // ����
int Graph[MaxVet][MaxVet];   // ����ͼ
bool flag[MaxVet]{};         // ������ʱ�־

// ��������ͼ
void CreateGraph() {
  fill(Graph[0], Graph[0] + n * n, Inf);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int w{};
      cin >> w;
      Graph[i][j] = w;
    }
  }
}

// Prime�㷨
// �������ͼ��ͨ���򷵻���С��������Ȩֵ
// �������ͼ����ͨ���򷵻�-1
int PrimeTree(int s) {
  int SumTree{};  // ��С��������Ȩֵ֮��

  // ��ʼ����־λ�;���
  fill(flag, flag + n, false);
  flag[s] = true;

  // Prime �����㷨
  for (int aa = 0; aa < n - 1; ++aa) {  // ֻ���ҵ�n-1����
    // ��δ�����ʵĶ������ҵ���s��������С����Ϊ��һ������
    int jj{-1}, m{Inf};
    for (int i = 0; i < n; ++i) {
      if (flag[i]) {
        for (int j = 0; j < n; ++j) {
          int w = Graph[i][j];
          if (!flag[j] && w && w < m) {  // w��Ҫ������0
            m = w;
            jj = j;
          }
        }
      }
    }
    // �������δ��ͨ�ĵ㣬ֱ�Ӿͷ���-1
    if (jj == -1) {
      return -1;
    }
    flag[jj] = true;  // ���򣬱�Ǹö����ѱ�����
    SumTree += m;
  }

  return SumTree;
}

int main() {
  CreateGraph();         // ��������ͼ
  cout << PrimeTree(0);  // ������С��������Ȩֵ֮��, �����ԭ��0��ʼ����
  return 0;
}
