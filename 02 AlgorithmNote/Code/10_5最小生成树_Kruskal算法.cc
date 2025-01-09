// ��С������_Kruskal
// Ҫ������ͼ��ͨ���ҵ�һ�����ܹ��������еĶ��㣬
// ������ϵ�Ȩֵ֮��Ҫ����С�ģ������Ľṹ��Ψһ��
// ����СȨֵ��Ψһ�ġ�
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
  int u;  // ������
  int v;  // ������
  int w;  // �ñߵ�Ȩֵ
};

const int Inf = 0x3FFFFFFF;  // �Զ��������
const int MaxVet = 100000;   // ������
int n{}, m{};                // ���㣬����
Edge Graph[MaxVet];          // ����ͼ
int FatherSet[MaxVet]{};       // �����ʵĶ��㼯��

// ��������ͼ
void CreateGraph() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    // ��������Խ�綼���������
    cin >> Graph[i].u >> Graph[i].v >> Graph[i].w;  // ��ʼ���㣬��ֹ���㣬��Ȩ
  }
}

// ��sort�����ıȽ������
bool CompareEdge(Edge e1, Edge e2) {
  return e1.w < e2.w;
}

int FindSet(int n) {
  int a = n;
  // Ѱ�Ҹ��ڵ�
  while (a != FatherSet[a]) {
    a = FatherSet[a];
  }
  // ѹ��·��
  // �Ѿ��������нڵ�ĸ��ڵ㶼��Ϊ���ڵ�
  int b = n;
  while (b != FatherSet[b]) {
    int c = FatherSet[b];
    FatherSet[b] = a;
    b = c;
  }
  return a;
}

// Kruskal�㷨
// �������ͼ��ͨ���򷵻���С��������Ȩֵ
// �������ͼ����ͨ���򷵻�-1
int KruskalTree(int s) {
  int SumTree{};                        // ��С��������Ȩֵ֮��
  int NumEdge{};                        // ��С�������ıߵĸ���
  sort(Graph, Graph + m, CompareEdge);  // �Ա�Ȩ��������
  for (int i = 0; i < n; ++i) {         // ��ʼ��
    FatherSet[i] = i;
  }
  for (int i = 0; i < m; ++i) {
    int Fu = FindSet(Graph[i].u);
    int Fv = FindSet(Graph[i].v);
    if (Fu != Fv) {      // ���u��v����ͬһ����ͨ���ϣ����Կ��Լ��뵽��С��������
      FatherSet[Fu] = Fv;  // �ϲ���������
      SumTree += Graph[i].w;
      ++NumEdge;
      if (NumEdge == n- 1) {  // ��С������ֻ��n-1����
        return SumTree;
      }
    }
  }
  return -1;  // ���������ͼ����ͨ������С������
}

int main() {
  CreateGraph();  // ��������ͼ
  cout << KruskalTree(0);  // ������С��������Ȩֵ֮��, �����ԭ��0��ʼ����
  return 0;
}
