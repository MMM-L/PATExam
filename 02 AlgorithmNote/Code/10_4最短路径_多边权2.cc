// ���·���������Ȩ2������Ȩֵ����Ȩ����Ҫ���·�����
// ����Dijkstra�㷨
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main() {
  const int MaxVet = 100;  // ��󶥵���
  const int Inf = 0x3FFFFFFF;
  int Graph[MaxVet][MaxVet]{};
  int n{}, m{}, s{}, t{};  // ������������������ţ��յ���
  int w1[MaxVet]{};        // ���еĶ³�ָ��
  bool flag[MaxVet]{};     // ������ʱ�־
  int dist[MaxVet]{};      // ��Զ����
  float sumw1[MaxVet]{};   // ���ﵱǰ����Ķ³�ָ��֮��
  float avw1[MaxVet]{};    // ���ﵱǰ����Ķ³�ָ����ƽ��ֵ
  int preu[MaxVet]{};      // ǰһ�������
  int flooru[MaxVet]{};    // ÿһ�������
  stack<int> PrintTrack;   // �������·��ֵ

  // ������еĻ�������
  cin >> n >> m >> s >> t;
  for (int i = 0; i < n; ++i) {
    cin >> w1[i];
  }
  // �������ͼ֮�������
  fill(&Graph[0][0], &Graph[0][0] + MaxVet * MaxVet, Inf);  // ��ʼ��
  for (int i = 0; i < m; ++i) {
    int u{}, v{}, w2{};
    cin >> u >> v >> w2;
    Graph[u][v] = w2;
    Graph[v][u] = w2;
  } 

  // Dijkstra�㷨
  fill(dist, dist + MaxVet, Inf);
  fill(flag, flag + MaxVet, false);
  dist[s] = 0;
  flooru[s] = 1;     // ��ʼ����Ĳ���Ϊ1
  sumw1[s] = w1[s];  // ��ʼ������ܶ³�ָ��
  avw1[s] = w1[s];   // ��ʼ�����ƽ���³�ָ��
  for (int i = 0; i < n; ++i) {
    // ���ҵ���������Ķ���u
    int u = -1;
    int m = Inf;
    for (int j = 0; j < n; ++j) {
      if (dist[j] < m && flag[j] == false) {
        m = dist[j];
        u = j;    // ��¼�˶���
      }
    }
    if (u == -1) { // δ�ҵ�����ľ��룬˵��ʣ�µĶ����s��㲻��ͨ
      break;
    }
    flag[u] = true;     // �˶������ڱ�����
    
    // ���ʴ�u�ɵ���Ķ��㣬��������̾���
    for (int v = 0; v < n; ++v) {
      if (flag[v] == false &&    // v����û�б�����
          Graph[u][v] < Inf &&   // �˶�������ͨ��
          dist[u] + Graph[u][v] <= dist[v]) {
        int floor = flooru[u] + 1;   // ���´�ʱ�ķ��ʲ���
        float s = sumw1[u] + w1[v];  // ��õ�ǰ������ܶ³�ָ�� 
        float avs = s / floor;       // ��õ�ǰ����Ķ³���ƽ��ָ��
        if (dist[u] + Graph[u][v] < dist[v]) {
          dist[v] = dist[u] + Graph[u][v];
          sumw1[v] = s;
          flooru[v] = floor;
          avw1[v] = avs;
          preu[v] = u;
        }
        if (dist[u] + Graph[u][v] == dist[v] && 
            avs < avw1[v]) {
          sumw1[v] = s;
          flooru[v] = floor;
          avw1[v] = avs;
          preu[v] = u;
        }
      }
    }
  }

  // ������·��ֵ(��������СȨֵ��)
  for (int i = t; i != s; i = preu[i]) {
    PrintTrack.push(i);
  }
  PrintTrack.push(s);
  cout << dist[t] << ' ';
  while (!PrintTrack.empty()) {
    cout << PrintTrack.top();
    if (PrintTrack.top() != t) {
      cout << "->";
    }
    PrintTrack.pop();
  }

  return 0;
}
