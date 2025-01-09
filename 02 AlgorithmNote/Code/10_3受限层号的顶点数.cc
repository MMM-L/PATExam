#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> Graph[100];  // �洢ͼ
queue<int> q;            // ���У��洢����
int n{}, m{}, s{}, k{};  // ͼ�Ķ���������������ʼ�����ţ����޵Ĳ���
bool flag[100]{false};   // ������ʱ�־
int dist[100]{};         // ����ʼ����ľ���
int distan{};            // ��ǰ����
int cntk{};              // ����������k�ĸ���

// ����ͼ������ͼ
void Create() {
  cin >> n >> m >> s >> k;
  for (int i = 0; i < m; ++i) {
    int u{}, v{};  // �����˵�ı��
    cin >> u >> v;
    Graph[u].push_back(v);
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

int main() {
  // ��������ͼ
  Create();
  // ��s�㿪ʼ
  BFS(s);

  for (int i = 0; i < n; ++i) {
    if (dist[i] <= k && flag[i] == true) {  // ������Ҫע������ͼ�Ӹö��㿪ʼʱ����һ����ͨ
      ++cntk;
    }
  }
  cout << cntk;
  return 0;
}
