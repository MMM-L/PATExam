// Exercise��Maximum Sequence Sum
#include<iostream>


using namespace std;


int main()
{
	int a[10050] = { 0 };
	int n = 0;
	int ThisSum = 0, MaxSum = -1;
	int left = 0, templeft = 0, right = 0;

	// �ȴ�������
	cin >> n;
	right = n - 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	// �������ݵĴ���
	for (int i = 0; i < n; i++)
	{
		ThisSum += a[i];
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
			right = i;
			left = templeft;
		}
		else if (ThisSum < 0)
		{
			ThisSum = 0;
			templeft = i + 1;
		}
	}

	if (MaxSum >= 0)
	{
		cout << MaxSum << " " << a[left] << " " << a[right];
	}
	else
	{
		cout << 0 << " " << a[0] << " " << a[n-1];
	}
	return 0;
}
