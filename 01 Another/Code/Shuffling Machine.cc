// Author: MMM
// https://pintia.cn/problem-sets/17/exam/problems/264
// �ظ�ϴ��
// ��Ŀ��Ҫ���е��������

#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n = 0;
	string shuff[54];
	string temp_shuff[54];
	int order[54] = { 0 };

	// ����ϴ�ƵĴ���
	cin >> n;

	// ����ϴ�ƵĴ���
	for (int i = 0; i < 54; ++i)
	{
		cin >> order[i];
	}

	// �Ƶĳ�ʼλ��
	for (int i = 0; i < 52; i++)
	{
		int j = i / 13;
		if (j == 0)
			shuff[i] += 'S';
		else if (j == 1)
			shuff[i] += 'H';
		else if (j == 2)
			shuff[i] += 'C';
		else
			shuff[i] += 'D';
		// ��������е㲻̫֪��
		shuff[i] += to_string(i % 13 + 1);
	}
	shuff[52] = "J1";
	shuff[53] = "J2";


	for (int i = 0; i < n; i++)
	{
		// ����Ҫ��Ĵ��򣬵����ƵĴ���
		// ��ѭ��Ϊ�����Ĵ���
		for (int i = 0; i < 54; i++)
		{
			temp_shuff[order[i] - 1] = shuff[i];
		}
		// �����ƵĴ���
		for (int i = 0; i < 54; i++)
		{
			shuff[i] = temp_shuff[i];
		}
	}

	for (int i = 0; i < 54; i++)
	{
		cout << shuff[i];
		cout << ' ';
	}
	return 0;
}
