// ��С������_Prime�㷨��������Dijkstra�㷨
// Ҫ������ͼ��ͨ���ҵ�һ�����ܹ��������еĶ��㣬
// ������ϵ�Ȩֵ֮��Ҫ����С�ģ������Ľṹ��Ψһ��
// ����СȨֵ��Ψһ�ġ�
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
  int v;  // �¸�������
  int w;  // �ñߵ�Ȩֵ
  // ���캯��
  Edge(int vv, int ww) : v(vv), w(ww) {}
};

const int Inf = 0x3FFFFFFF;  // �Զ��������
const int MaxVet = 100;      // ��ඥ����
int n{}, m{};                // ���㣬����
vector<Edge> Graph[MaxVet];  // ����ͼ
bool flag[MaxVet]{};         // ������ʱ�־

// ��������ͼ
void CreateGraph() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u{}, v{}, w{};  // ��ʼ���㣬��ֹ���㣬��Ȩ
    cin >> u >> v >> w;
    Graph[u].push_back(Edge(v, w));
    Graph[v].push_back(Edge(u, w));  // ����������ͼ
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
  for (int aa = 0; aa < n-1; ++aa) {
    // ��δ�����ʵĶ������ҵ���s��������С����Ϊ��һ������
    // ��һ������ֻ��n-1��
    int jj{-1}, m{Inf};
    for (int i = 0; i < n; ++i) {
      if (flag[i]) {
        for (int j = 0; j < Graph[i].size(); ++j) {
          int v = Graph[i][j].v;
          int w = Graph[i][j].w;
          if (!flag[v] && w < m) {
            m = w;
            jj = v;
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
  CreateGraph();  // ��������ͼ
  cout << PrimeTree(0);  // ������С��������Ȩֵ֮��, �����ԭ��0��ʼ����
  return 0;
}
