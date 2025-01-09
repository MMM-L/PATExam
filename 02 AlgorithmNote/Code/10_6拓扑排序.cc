#include<iostream>
#include<queue>
using namespace std;

const int MaxVet = 100;       // ���Ķ�����
int n{}, m{};  // ������������
int Graph[MaxVet][MaxVet]{};  // ����ͼ
int NumInputV[MaxVet]{};  // ÿ����������
int Flag{};  // ��������������
priority_queue<int, vector<int>, greater<int>>Input0;  // ���Ϊ0�����ȶ��У�С�Ķ�������ǰ��

void CreatGraph() {
  int u{}, v{};  // ������
  cin >> n >> m;  // ͼ�Ķ�����������
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    ++NumInputV[v];  // ��ȼ�һ
    Graph[u][v] = 1;
  }
}

int main() {
  CreatGraph();  // ��������ͼ����ͳ��ÿ������������Ϣ
  for (int i = 0; i < n; ++i) {
    if (!NumInputV[i]) {  // ���Ϊ0�Ķ���������ȶ���
      Input0.push(i);
    }
  }

  while (!Input0.empty()) {  // ֻҪ���ȶ��в�Ϊ��
    int u = Input0.top();
    Input0.pop();
    if (Flag) {  // ������ǵ�һ������ţ�ǰ�涼����ո�
      cout << ' ';
    }
    cout << u;
    ++Flag;
    for (int i = 0; i < n; ++i) {
      if (Graph[u][i]) {
        --NumInputV[i];
        if (!NumInputV[i]) {
          Input0.push(i);
        }
      }
    
    }
  }
  if (Flag < n) {
    cout << "���������޻�ͼ";
  }
  return 0;
}
