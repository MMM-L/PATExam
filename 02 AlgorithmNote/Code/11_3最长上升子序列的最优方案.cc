#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 100;
int a[MAXN]{};
vector<int> a_vector[MAXN]{};  // ÿ��a����Ӧ������������

int main() { 
  int n {}, MaxLength{};
  cin >> n;
  for (int i = 0; i < n; ++i) {  // ��������
    cin >> a[i];
  }
  a_vector[0].push_back(a[0]);     // ��ʼ����һ��a����Ӧ�����������У�����������
  MaxLength = a_vector[0].size();  // ���ʱ������������
  for (int i = 1; i < n; ++i) {
    a_vector[i].push_back(a[i]);   // ��ʼÿ��a����Ӧ�����������о���������
    for (int j = 0; j < i; ++j) {  // �мǴ�ǰ������������������Ȼ��������ŵ�Ҫ�󣨶����ǴӺ��濪ʼ������
      if (a[i] >= a[j] && a_vector[i].size() <= a_vector[j].size()) {
        a_vector[i] = a_vector[j];
        a_vector[i].push_back(a[i]);  // ����˿�����е�ֵ
      }
    }
    if (a_vector[i].size() > MaxLength) {  // ��¼��ǰ������г���
      MaxLength = a_vector[i].size();
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a_vector[i].size() == MaxLength) {  // ��һ����������о�����������Ҫ��
      cout << MaxLength << endl;
      cout << a_vector[i][0];
      for (int j = 1; j < a_vector[i].size(); ++j) {
        cout << ' ' << a_vector[i][j];
      }
      break;  // ���滹�еĻ�����ž�����ڵ�һ�����������
    }
  }
  // ���
  return 0;
}