#include<iostream>
using namespace std;

const int MaxN = 10005;
int dp[MaxN]{0};

// ���ڵ����n��¥�ݿ�����n-1ֱ������ȥ��Ҳ������n-2ֱ������ȥ
// ��쳲����������е���
int main(void) {

  int n{};
  cin >> n;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; ++i) {
    dp[i] = (dp[i - 1] + dp[i - 2])%10007;
  }
  cout << dp[n];
  return 0;
}
