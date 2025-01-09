#include<iostream>
#include<vector>
using namespace std;

const int max_n = 100;  // ��󶥵���
vector<int> Vgraph[max_n];
int n{}, m{};       // �������ͱ���
bool vis[max_n]{};  // ������ʱ��

// ��ͼ
void BuildGraph() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int temp1{}, temp2{};
    cin >> temp1 >> temp2;
    Vgraph[temp1].push_back(temp2);
    Vgraph[temp2].push_back(temp1);
  }
}

// �����������
void DFS(int n) {
  vis[n] = true;
  for (int i = 0; i < Vgraph[n].size(); ++i) {
    if (vis[Vgraph[n][i]] == false) {
      DFS(Vgraph[n][i]);
    }
  }
}

// ������ͨͼ������
int CountSubGraph() {
  int num{};
  for (int i = 0; i < n; ++i) {
    if (vis[i] == false) {
      ++num;  // ��¼��ͨͼ������
      DFS(i);
    }
  }
  return num;
}

int main() {
  // �������뽨��ͼ
  BuildGraph();
  // ����������������㷨��������ͨͼ������
  cout << CountSubGraph();
  return 0;
}