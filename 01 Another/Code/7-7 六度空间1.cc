#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int Max_N = 1002;
const int MY_INF = 0x7FFFFFFF;

struct Node {
  int v;
  int w;
  Node(int _v, int _w) : v(_v), w(_w){};
};  // ���㷽ʽ

int N{}, M{};
vector<Node> Graph[Max_N]{};
int dist[Max_N]{};
bool flag[Max_N]{};
double sum_num{};

void Dijkstra(int start) {
  dist[start] = 0;  // ��ʼ����ľ���Ϊ0

  // ÿ�����㶼Ҫ�����ʵ�
  for (int i = 1; i <= N; ++i) {
    // step1���ҵ���̾��룬��δ�����ʵ�
    int u = -1, max_value = MY_INF;
    for (int j = 1; j <= N; ++j) {
      if (dist[j] < max_value && !flag[j]) {
        u = j;
        max_value = dist[j];
      }
    }
    if (u == -1) {  // ���ඥ�㶼����ͨ
      return;
    }

    // step2���Ӹö��㿪ʼ������̾���
    for (int j = 0; j < Graph[u].size(); ++j) {
      if (dist[u] + Graph[u][j].w < dist[Graph[u][j].v]) {  // �������Ȩ��
        dist[Graph[u][j].v] = Graph[u][j].w + dist[u];
      }
    }
    flag[u] = true;
  }
}

int main() {
  // ����ÿ�����֮��Ĺ�ϵ������ͼ��ʾ
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int u{}, v{};
    cin >> u >> v;
    Graph[u].push_back(Node(v, 1));
    Graph[v].push_back(Node(u, 1));
  }

  for (int i = 1; i <= N; ++i) {
    // step1: ���ඥ��ľ����ȼ��趼Ϊ�����
    fill(dist + 1, dist + 1 + N, MY_INF);
    fill(flag + 1, flag + 1 + N, false);
    sum_num = 0;

    // step2: �����ÿһ�����������ͼ�����ඥ�����̾���
    Dijkstra(i);

    // step3��ͳ��֮��ľ���С��6������
    for (int j = 1; j <= N; ++j) {
      if (dist[j] <= 6) {
        ++sum_num;
      }
    }
    cout << i << ": ";
    printf("%.2f", (sum_num / N) * 100);
    cout << '%' << endl;
  }

  return 0;
}
