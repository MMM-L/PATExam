#include<iostream>
using namespace std;

int main()
{
  int n{}, m{}, flag{};
  char grap[100][100]{};  // ʹ���ڽӾ���Ĵ洢��ʽ
  // n�����㣬m����
  cin >> n >> m;
  // ����ͼ�����ӷ�ʽ
  for (int i = 0; i < m; i++) {
    int temp1{}, temp2{};
    cin >> temp1 >> temp2;
    grap[temp1][temp2] = 1;
    grap[temp2][temp1] = 1;
  }
  // ͳ�ƶ���Ķ�
  for (int i = 0; i < n; i++) {
    int temp1{};
    for (int j = 0; j < n; j++) {
      if (grap[i][j] == 1) {
        ++temp1;
      }
    }
    if (flag) {
      cout << ' ';
    }
    flag = 1;
    cout << temp1;
  }
  return 0;
}