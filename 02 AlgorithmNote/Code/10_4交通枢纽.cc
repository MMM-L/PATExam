// Dijkstra�㷨
// �����ԣ�1.ֻ����Ե�Դ����С·���� 2. ͼ��Ȩֵֻ��Ϊ����
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
  int next;                                   // ��һ�������
  int weight;                                 // ��������֮���Ȩֵ
  Node(int v, int w) : next(v), weight(w) {}  // ���캯����������ʼ��
};
struct ImportantCity {
  int CityNum;
  int CitySum;
};

const int Maxv = 100;        // ��󶥵���
const int inf = 0x3FFFFFFF;  // ����һ�������
vector<Node> Graph[Maxv];    // ����ͼ���ڽӱ��ʾ
int n{}, m{}, k{};           // ����������������ʼ�����ţ��յ���
bool flag[Maxv]{false};      // ������ʱ�־
int MinDist[Maxv]{};         // ��ǰ����ʼ���㵽�����������̾���
int Start[Maxv]{};           // ��ѡ�ĳ��к�
ImportantCity City[Maxv];    // ��ѡ���е���Ϣ

// ��������ͼ
void create() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int u{}, v{}, w{};
    cin >> u >> v >> w;  // ���붥�㣬�߼�Ȩֵ
    Graph[u].push_back(Node(v, w));
    Graph[v].push_back(Node(u, w));  // ����������ͼ
  }
  for (int i = 0; i < k; ++i) {
    cin >> Start[i];  // ���뱸ѡ���к�
  }
}

// ���·���������㷨
void Dijkstra(int start) {
  // ��ʼ������
  fill(MinDist, MinDist + n, 0x3FFFFFFF);
  fill(flag, flag + n, false);
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
      if (flag[v] == false && MinDist[u] + w < MinDist[v]) {
        MinDist[v] = MinDist[u] + w;  // ������̾���
      }
    }
  }
}

// ����֮��ıȽ�
bool CityCompare(ImportantCity C1, ImportantCity C2) {
  if (C1.CitySum != C2.CitySum) {
    return C1.CitySum < C2.CitySum;
  } else {
    return C1.CityNum < C2.CityNum;
  }
}

//int main() {
//  create();     // ��������ͼ
//  for (int i = 0; i < k; ++i) {
//    int sum = 0;
//    Dijkstra(Start[i]);  // �ҵ��˳��е����г���֮������·��
//    for (int j = 0; j < n; ++j) {
//      sum += MinDist[j];
//    }
//    City[i].CityNum = Start[i];
//    City[i].CitySum = sum;
//  }
//  sort(City, City + k, &CityCompare);
//  // �����ͨ��Ŧ����
//  cout << City[0].CityNum << ' ' << City[0].CitySum;
//  return 0;
//}

// �Ƚ��㷨����һ��д��
int main() {
  create();                      // ��������ͼ
  int CitySum = inf, CityNum{};  // ���ǶԱȵ�ֵ
  for (int i = 0; i < k; ++i) {
    int sum = 0;
    Dijkstra(Start[i]);  // �ҵ��˳��е����г���֮������·��
    for (int j = 0; j < n; ++j) {
      sum += MinDist[j];
    }
    if (sum < CitySum) {
      CitySum = sum;
      CityNum = Start[i];
    } else if (sum == CitySum) {
      if (Start[i] < CityNum) {
        CityNum = Start[i];
      }
    }
  }
  // �����ͨ��Ŧ����
  cout << CityNum << ' ' << CitySum;
  return 0;
 }