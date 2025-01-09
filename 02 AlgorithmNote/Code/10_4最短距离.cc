// Dijkstra�㷨
// �����ԣ�1.ֻ����Ե�Դ����С·���� 2. ͼ��Ȩֵֻ��Ϊ����
#include<iostream>
#include<vector>
using namespace std;

const int Maxv = 100;        // ��󶥵���
const int inf = 0x3FFFFFFF;  // ����һ�������
struct Node {
  int next;                                   // ��һ�������
  int weight;                                 // ��������֮���Ȩֵ
  Node(int v, int w) : next(v), weight(w) {}  // ���캯����������ʼ��
};
vector<Node> Graph[Maxv];  // ����ͼ���ڽӱ��ʾ
int n{}, m{}, s{}, t{};    // ����������������ʼ�����ţ��յ���
bool flag[Maxv]{false};    // ������ʱ�־
int MinDist[Maxv]{};       // ��ǰ����ʼ���㵽�����������̾���

// ��������ͼ
void create() {
  cin >> n >> m >> s >> t;
  for (int i = 0; i < m; ++i) {
    int u{}, v{}, w{};
    cin >> u >> v >> w;  // ���붥�㣬�߼�Ȩֵ
    Graph[u].push_back(Node(v, w));
    Graph[v].push_back(Node(u, w));  // ����������ͼ
  }
}

// ���·���������㷨
void Dijkstra(int start) {
  // ��ʼ������
  fill(MinDist, MinDist + n, 0x3FFFFFFF);
  MinDist[start] = 0;  // ��ʼ���㵽����ľ�����Ϊ0
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
      int v = Graph[u][j].next;    // ���Է��ʵĶ�����
      int w = Graph[u][j].weight;  // u-->v��Ȩֵ
      if (MinDist[u] + w < MinDist[v]) {
        MinDist[v] = MinDist[u] + w; // ������̾���
      }
    }
  }  
}

int main() {

  create();     // ��������ͼ
  Dijkstra(s);  // ��s��ʼ������������������·��
  // ���s-->t�����·��ֵ
  if (MinDist[t] < inf) {
    cout << MinDist[t];
  } else {
    cout << -1;
  }
  return 0;
}
