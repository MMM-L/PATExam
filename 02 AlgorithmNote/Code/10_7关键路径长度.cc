// �ؼ�·������
#include<iostream>
#include<queue>
using namespace std;

const int MaxVertex = 100;
const int INF = 0x3FFFFFFF;
int n{}, m{};
int Graph[MaxVertex][MaxVertex]{};
int InputDegreeNumber[MaxVertex]{};
int NumberVertex{};
queue<int> InputDegreeNumber0;

void CreatGraph() {
  int u{}, v{}, w {};
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    Graph[u][v] = w;
    ++InputDegreeNumber[v];
  }
}




int main() {
  // ��������ͼ
  CreatGraph();

  // ������������
  for (int i = 0; i < n; ++i) {
    if (!InputDegreeNumber[i]) {
      InputDegreeNumber0.push(i);  // �����Ϊ0�Ķ������
    }
  }
  while (!InputDegreeNumber0.empty()) {
    int u = InputDegreeNumber0.front();
    InputDegreeNumber0.pop();
    for (int i = 0; i < n; ++i) {
      if (Graph[u][i]) {
        --InputDegreeNumber[i];
        if (!InputDegreeNumber[i]) {
          InputDegreeNumber0.push(i);
        }
      }
    }
    ++NumberVertex;
  }
  if (NumberVertex < n) {
    cout << "No";
    return 0;
  }
  cout << "Yes";



  return 0;
}
