// �����Բ���
#include<iostream>
#include<math.h>

using namespace std;


int main()
{
	int N = 0, Sum = 0;  // �ܵĸ���
	int k = 0, j = 0;  // �����ʶ
	double temp = 0;  // ��ʱ����
	int Prime[2] = { 0 };  // ���ڵ���������
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		// �ж��Ƿ�Ϊ����
		temp = sqrt(i);
		for (j = 2; j <= temp; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j > temp)  // Ϊ����
		{
			Prime[(k % 2)] = i;
			k++;
			if (abs(Prime[0] - Prime[1]) == 2)
			{
				Sum++;
			}
		}
	}
	cout << Sum;
	return 0;
}