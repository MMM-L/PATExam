#include <iostream>
using namespace std;

int main() {
  int n{}, m{}, flag{};
  int grap[100][100]{};  // ʹ���ڽӾ���Ĵ洢��ʽ
  // n�����㣬m����
  cin >> n >> m;
  // ����ͼ�����ӷ�ʽ
  for (int i = 0; i < m; i++) {
    int temp1{}, temp2{};
    cin >> temp1 >> temp2;
    grap[temp1][temp2] = 1;
    grap[temp2][temp1] = 1;
  }

  for (int i = 0; i < n; i++) {
    flag = 0;
    for (int j = 0; j < n; j++) {
      if (flag) {
        cout << ' ';
      }
      flag = 1;
      cout << grap[i][j];
    }
    cout << endl;
  }
  return 0;
}