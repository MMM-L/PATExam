// Author:MMM
// https://pintia.cn/problem-sets/17/exam/problems/263

#include<iostream>
using namespace std;

int main()
{
	// ������20λ���µ�����
	char a[21] = { 0 };
	char b[21] = { 0 };
	int visa[10] = { 0 };
	int visb[10] = { 0 };
	int n = 0, flag = 0;
	cin >> a;

	// �������ݣ�ÿλת��Ϊʮ����
	// �������ݷ���
	for (int i = 0; a[i] != '\0'; i++)
	{
		a[i] -= '0';
		visa[int(a[i])]++;  // ��¼a��ÿ�����ֳ��ֵĴ���
		b[i] = 2 * a[i];
		n++;  // ��¼�������ݵĳ���
	}
	for (int i = n - 1; i > 0; i--)
	{
		if (b[i] > 9)
		{
			b[i] -= 10;
			b[i - 1] += 1;
		}
		visb[int(b[i])]++;  // ��¼b��ÿ�����ֳ��ֵĴ���
	}

	// �Ա����������Ƿ�����ͬ���������
	if (b[0] > 9)
	{
		cout << "No" << endl;
	}
	else
	{
		visb[int(b[0])]++;  // ��¼b��ÿ�����ֳ��ֵĴ���

		// Ȼ�����visa��visb�ж���������
		for (flag = 0; flag < 10; flag++)
		{
			if (visa[flag] != visb[flag])
			{
				break;
			}
		}

		if (flag == 10)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

	// ��������Ҫ��Ҫ��������Ľ��
	for (int i = 0; i < n; i++)
	{
		cout << int(b[i]);
	}
	return 0;
}
