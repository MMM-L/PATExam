// ����Դ���·���㷨
// Floyd�㷨
#include <iostream>
#include <algorithm>
using namespace std;

// ���þ������ʽ�洢ͼ
const int maxvet = 50;
const int myinf = 0x3fffffff;
int graph[maxvet][maxvet]{};
int dist[maxvet][maxvet]{};  // ÿ�������̾������

int main() {
  int n{}, m{};  // ���㣬����
  cin >> n >> m;
  // ������ڶ�ά�����ָ����Ҫ�������
  fill(graph[0], graph[0] + maxvet * maxvet, myinf);  // graph[0] == &graph[0][0]
  fill(dist[0], dist[0] + maxvet * maxvet, myinf);
  for (int i = 0; i < m; ++i) {
    int u{}, v{}, w{};  // ��ʼ���㣬��ֹ���㣬Ȩ��
    cin >> u >> v >> w;
    graph[u][v] = w;  // ��������ͼ, �ڽӾ���
    graph[v][u] = w;
    dist[u][v] = w;  // ��������ͼ, �ڽӾ���
    dist[v][u] = w;
  }

  // ����ѭ����Floyd�㷨
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (graph[i][k] != myinf && graph[k][j] != myinf) {
          // i->k->j������ͨ
          if (dist[i][k] + dist[k][j] < dist[i][j]) {
            // ����i->j�ľ���
            dist[i][j] = dist[i][k] + dist[k][j];  // �費��Ҫdist[j][i]
          }
        }
      }
    }
  }

  // �������
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        dist[i][j] = 0;
      }
      if (dist[i][j] == myinf) {  // �޷�����
        dist[i][j] = -1;
      }
      if (j != 0) {
        cout << ' ';
      }
      cout << dist[i][j];
    }
    cout << endl;
  }



  return 0;
}









