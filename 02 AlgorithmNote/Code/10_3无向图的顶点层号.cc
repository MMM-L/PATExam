// ���������Գ���Ϊ���·������ Dijksta?
// ��磬ֱ���ù�������㷨��OKFOK
// ������ͨͼ�������㿪ʼ����
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> Graph[100];  // �洢ͼ
queue<int> q;            // ���У��洢����
int n{}, m{}, s{};       // ͼ�Ķ���������������ʼ������
bool flag[100]{false};   // ������ʱ�־
int dist[100]{};         // ����ʼ����ľ���
int distan{};          // ��ǰ����

// ����ͼ������ͼ
void Create() {
  cin >> n >> m >> s;
  for (int i = 0; i < m; ++i) {
    int u{}, v{};  // �����˵�ı��
    cin >> u >> v;
    Graph[u].push_back(v);
    Graph[v].push_back(u);
  }
}

// ��������㷨
void BFS(int sv) {
  q.push(sv);
  flag[sv] = true;
  while (!q.empty()) {
    int cnt = q.size();  // �ò�ĸ���
    for (int j = 0; j < cnt; ++j) {
      int tv = q.front();  // ȡ���е��׸�
      q.pop();
      dist[tv] = distan;
      for (int i = 0; i < Graph[tv].size(); ++i) {
        if (flag[Graph[tv][i]] == false) {  // δ��ӵĲ������
          q.push(Graph[tv][i]);
          flag[Graph[tv][i]] = true;  // ��ӱ�־
        }
      }
    }
    ++distan;  // �ò������������һ
  }
}

int main()
{
  // ��������ͼ
  Create();
  // ��s�㿪ʼ
  BFS(s);

  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      cout << dist[i];
    } else {
      cout << ' ' << dist[i];
    }
  }
  return 0;
}
