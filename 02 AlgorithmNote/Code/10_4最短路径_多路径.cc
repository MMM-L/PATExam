// Dijkstra�㷨
// �����ԣ�1.ֻ����Ե�Դ����С·���� 2. ͼ��Ȩֵֻ��Ϊ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxv = 100;        // ��󶥵���
const int inf = 0x3FFFFFFF;  // ����һ�������
struct Node {
  int next;                                   // ��һ�������
  int weight;                                 // ��������֮���Ȩֵ
  Node(int v, int w) : next(v), weight(w) {}  // ���캯����������ʼ��
};
vector<Node> Graph[Maxv];        // ����ͼ���ڽӱ��ʾ
vector<int> Track[Maxv];         // ���·������һ���ڵ�
vector<int> temPath;             // ���е�һ��·��
vector<vector<int>> Path;        // ���·��(���һ������)
int n{}, m{}, s{}, t{};          // ����������������ʼ�����ţ��յ���
bool flag[Maxv]{false};          // ������ʱ�־
int MinDist[Maxv]{};             // ��ǰ����ʼ���㵽�����������̾���
int MinCoun[Maxv]{};             // ��¼���·��������

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
  MinCoun[start] = 1;
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
      if (!flag[v]) {
        if (MinDist[u] + w < MinDist[v]) {
          MinDist[v] = MinDist[u] + w;  // ������̾���
          MinCoun[v] = MinCoun[u];
          Track[v].clear();  // ����ҵ��˸��ٵģ���Ҫ��֮ǰ�Ķ������
          Track[v].push_back(u);
        } else if (MinDist[u] + w == MinDist[v]) {
          MinCoun[v] += MinCoun[u];
          Track[v].push_back(u);
        }
      }
    }
  }
}


// ����·��
void PresentTrack(int nv) {
  if (nv == s) {
    temPath.push_back(nv);
    Path.push_back(temPath);
    temPath.pop_back();
  } else {
    temPath.push_back(nv);
    for (int ii = 0; ii < Track[nv].size(); ++ii) {
      PresentTrack(Track[nv][ii]);
    }
    temPath.pop_back();
  }
  return;
}

int main() {
  create();     // ��������ͼ
  Dijkstra(s);  // ��s��ʼ������������������·��

  // ���s-->t�����·������
  cout << MinCoun[t] << endl;

  // �������·��
  PresentTrack(t);
  for (int i = 0; i < Path.size(); ++i) {
    reverse(Path[i].begin(), Path[i].end());
  }

  // ��·����������
  sort(Path.begin(), Path.end());

  // ���ÿһ�����·��
  for (int i = 0; i < Path.size(); ++i) {
    temPath = Path[i];
    for (int j = 0; j < temPath.size(); ++j) {
      if (j > 0) {
        cout << "->";
      }
      cout << temPath[j];
    }
    cout << endl;
  }
  return 0;
}
