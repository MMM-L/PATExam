#include<iostream>
using namespace std;


int main() {
  int n{}, m{};
  cin >> n >> m;  // ���붥�����ͱ������ж��Ƿ�Ϊһ����

  if (m == n - 1) {  // ���е�һЩ��ϵʽȷʵҪ��ϰ��ϰ��
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}
