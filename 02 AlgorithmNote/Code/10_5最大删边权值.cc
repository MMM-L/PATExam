// ����˼·������ͼ�����б�Ȩ֮��Ϊһ��ֵ��
// Ϊ�˱�֤ɾ��������Ȩ��֮�����ͨ��
// Ҳ���Ǳ�����Ϊ��С��������
// �������С������֮�󣬱���Եõ����ɾ��Ȩ֮��

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int Max_N = 100;
struct Node {
  int v;  // ��һ���ڵ�
  int w;  // Ȩֵ
  Node(int x, int y) : v(x), w(y) {}
};
vector<Node> Graph[Max_N];
int n{}, m{};
bool flag[Max_N]{false};

// ��С������
int PrimeMinSpanTree(int start_i) {
  int dist[Max_N]{};
  int sum_min_tree{};
  fill(dist, dist + n, 0x7FFFFFFF);
  dist[start_i] = 0;  // �Ӷ���i��ʼ����

  // ���е㶼Ҫ���ʵ�
  for (int i = 0; i < n; ++i) {
    // ���ҵ�������Ǹ���
    int u = -1, min_u = 0x7FFFFFFF;
    for (int j = 0; j < n; ++j) {
      if (dist[j] < min_u && !flag[j]) {
        u = j;
        min_u = dist[j];
      }
    }
    if (u == -1) {  // ��ʱͼ�ǲ���ͨ��
      return -1;
    }
    // ��u��ʼ���ʣ������Ӧ�ߵĶ��㲻��
    flag[u] = true;
    sum_min_tree += min_u;
    for (int j = 0; j < Graph[u].size(); ++j) {
      int v = Graph[u][j].v;
      if (Graph[u][j].w < dist[v] && !flag[v]) {
        dist[v] = Graph[u][j].w;
      }
    }
  }
  return sum_min_tree;
}

int main() {
  int sum_w{}, min_sum_w{};

  fill(flag, flag + Max_N, 0);  // ����δ���ʵı�־

  // �������������ͼ
  // �ڽӾ������ʽ
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int t1{}, t2{}, w{};
    cin >> t1 >> t2 >> w;
    Graph[t1].push_back(Node(t2, w));
    Graph[t2].push_back(Node(t1, w));
    sum_w += w;  // �������б�Ȩ֮��
  }

  min_sum_w = PrimeMinSpanTree(0);
  if (min_sum_w == -1) {  // ����ͼ����ͨ
    cout << -1;
  } else {  // ������Ŀ�ɾ��Ȩ
    cout << sum_w - min_sum_w;
  }

  return 0;
}
