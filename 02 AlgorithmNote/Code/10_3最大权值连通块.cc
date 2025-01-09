#include<iostream>
#include<vector>
using namespace std;

int Weight[100]{0};        // �����Ȩֵ
int MaxWeightSubGraph{};   // ��¼��ͨ������Ȩֵ
int WeightSubGraph{};      // ��ʱ��Ȩֵ��¼����
int Vist[100]{0};          // ������ʼ�¼
vector<int> Graph[100]{};  // ͼ

void DFS(int Nv) {
  Vist[Nv] = 1;
  WeightSubGraph += Weight[Nv];  // ��¼��ͨͼ��Ȩֵ
  for (int i = 0; i < Graph[Nv].size(); ++i) {
    int temp = Graph[Nv][i];
    if (Vist[temp] == 0) {
      DFS(temp);
    }
  }
}

void VistGraph(int n) { 
  for (int i = 0; i < n; ++i) {
    if (Vist[i] == 0) {
      DFS(i);  // �������һ����ͨͼ
      if (WeightSubGraph > MaxWeightSubGraph) {
        // ������ͨͼ�����Ȩֵ
        MaxWeightSubGraph = WeightSubGraph;
      }
      WeightSubGraph = 0;  // ������Ҫ����һ��Ȩֵ�ļ�¼
    }
  }
}

int main() {
  int n{}, m{};
  cin >> n >> m;                 // ͼ�Ķ������ͱ���
  for (int i = 0; i < n; ++i) {  // �����Ӧ�����Ȩֵ
    cin >> Weight[i];
  }
  for (int i = 0; i < m; ++i) {
    int temp1{}, temp2{};
    cin >> temp1 >> temp2;
    Graph[temp1].push_back(temp2);  // ����ͼ
    Graph[temp2].push_back(temp1);
  }
  // ������ͨͼ
  VistGraph(n);
  // ��������ͨͼ��Ȩֵ
  cout << MaxWeightSubGraph << endl;
  return 0;
}