// Dijkstra�㷨
// �����ԣ�1.ֻ����Ե�Դ����С·���� 2. ͼ��Ȩֵֻ��Ϊ����
#include <iostream>
#include <vector>
using namespace std;

const int Maxv = 100;        // ��󶥵���
const int inf = 0x3FFFFFFF;  // ����һ�������
struct Node {
  int next;  // ��һ�������
  int w1;    // ����Ȩֵ
  int w2;    // ����Ȩֵ
  Node(int v, int ww1, int ww2)
      : next(v), w1(ww1), w2(ww2) {}  // ���캯����������ʼ��
};
vector<Node> Graph[Maxv];  // ����ͼ���ڽӱ��ʾ
vector<int> Path;          // ���·������С����
int n{}, m{}, s{}, t{};    // ����������������ʼ�����ţ��յ�
bool flag[Maxv]{false};    // ������ʱ�־
int MinDist[Maxv]{};       // ��ǰ����ʼ���㵽�����������̾���
int MinCost[Maxv]{};       // ��ǰ����ʼ���㵽������������ٻ���
int PreDist[Maxv]{};       // ����ö������С������С���ѵ���һ������

// ��������ͼ
void create() {
  cin >> n >> m >> s >> t;
  for (int i = 0; i < m; ++i) {
    int u{}, v{}, w1{}, w2{};
    cin >> u >> v >> w1 >> w2;  // ���붥�㣬�߼�Ȩֵ
    Graph[u].push_back(Node(v, w1, w2));
    Graph[v].push_back(Node(u, w1, w2));  // ����������ͼ
  }
}

// ���·���������㷨
void DijkstraDistCost(int start) {
  fill(MinDist, MinDist + n, 0x3FFFFFFF);  // ��ʼ������
  fill(MinCost, MinCost + n, 0x3FFFFFFF);  // ��ʼ������
  MinDist[start] = 0;  // ��ʼ���㵽����ľ�����Ϊ0
  MinCost[start] = 0;  // ��ʼ���㵽����Ļ�����Ϊ0
  PreDist[start] = start;
  for (int i = 0; i < n; ++i) {
    int u = -1, mind = inf;
    // �ҵ�������̵�δ���ʶ���
    for (int j = 0; j < n; ++j) {
      if (MinDist[j] < mind && flag[j] == false) {
        mind = MinDist[j];
        u = j;  // ������̵�δ���ʶ�����
      }
    }
    if (u == -1) {
      return;  // ���㶼û������ֱ�ӷ���
    }
    flag[u] = true;  // ��־�˶����ѷ���
    // ��u���㿪ʼ��������
    for (int j = 0; j < Graph[u].size(); ++j) {
      int v = Graph[u][j].next;  // ���Է��ʵĶ�����
      int w1 = Graph[u][j].w1;   // u-->v�ľ���Ȩֵ
      int w2 = Graph[u][j].w2;   // u-->v�Ļ���Ȩֵ
      if (MinDist[u] + w1 < MinDist[v]) {
        MinDist[v] = MinDist[u] + w1;  // ������̾���
        MinCost[v] = MinCost[u] + w2;  // ���´�ʱ�Ļ���
        PreDist[v] = u;
      } else if ((MinDist[u] + w1 == MinDist[v]) &&
                 (MinCost[u] + w2 < MinCost[v])) {
        // ���������ȣ�ȡ������С��
        MinCost[v] = MinCost[u] + w2;
        PreDist[v] = u;
      }
    }
  }
}


// ������̵�·��
void PresentPath(int nv) {
  if (nv == s) {  // ���Ϊ��ʼ�Ķ���
    Path.push_back(nv);
  } else {
    PresentPath(PreDist[nv]);
    Path.push_back(nv);
  }
  return;
}

int main() {
  create();             // ��������ͼ
  DijkstraDistCost(s);  // ��s��ʼ������������������·��
  cout << MinDist[t] << ' ' << MinCost[t] << ' ';
  // �������·��
  PresentPath(t);
  // ������·��
  for (int i = 0; i < Path.size(); ++i) {
    if (i > 0) {
      cout << "->";
    }
    cout << Path[i];
  }
  return 0;
}
