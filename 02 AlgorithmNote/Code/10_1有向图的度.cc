#include <iostream>
using namespace std;

int main() {
  int n{}, m{};
  char grap[100][100]{};  // 使用邻接矩阵的存储形式
  // n个顶点，m条边
  cin >> n >> m;
  // 输入图的连接方式
  for (int i = 0; i < m; i++) {
    int temp1{}, temp2{};
    cin >> temp1 >> temp2;
    grap[temp1][temp2] = 1;
  }
  // 统计顶点的度
  for (int i = 0; i < n; i++) {
    int temp1{}; // 入度
    int temp2{}; // 出度
    for (int j = 0; j < n; j++) {
      if (grap[j][i] == 1) {
        ++temp1;
      }
      if (grap[i][j] == 1) {
        ++temp2;
      }
    }
    cout << temp1 << ' ' << temp2 << endl;
  }
  return 0;
}