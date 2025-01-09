// �Ƚ��ؾ����㷨��ֱ���㷨������ʱ��
// ����ʽΪ��f(x)=2+0.3x+2.3x^2+3.6x^3+5.1x^4+6.2x^5
#include<stdio.h>
#include<math.h>
#include<time.h>
#define MaxTimes 10000000

// �ؾ����㷨
double QinDuo(int n, double a[], double x)
{
	double sum = a[n];
	for (int i = n - 1; i >= 0; i--)
	{
		sum = sum * x + a[i];
	}
	return sum;
}

// ֱ�Ӽ���
double DirectDuo(int n, double a[], double x)
{
	double sum = a[0];
	for (int i = 1; i <= n; i++)
	{
		sum = sum + a[i] * pow(x, i);
	}
	return sum;
}


int main()
{
	// nΪ����ʽ����������
	// ������洢����ʽ��ϵ����
	int n = 5;
	double a[6] = { 2, 0.3, 2.3, 3.6, 5.1, 6.2 };
	double x = 0;
	printf("�������ʽx��ȡֵ��");
	scanf_s("%lf", &x);
	printf("�ؾ��صļ��㷽����%lf\n", QinDuo(n, a, x));
	printf("  ֱ�Ӽ���ķ�����%lf\n", DirectDuo(n, a, x));

	// ��ʼ�������������ĵ�ʱ�䣬Ϊ�˶Աȸ������ԣ�ѭ������1000��
	// ���յ���ʾ��λ[s]
	clock_t start, stop;
	start = clock();
	for (int i = 0; i < MaxTimes; i++)
	{
		QinDuo(n, a, x);
	}
	stop = clock();
	printf("�ؾ��صļ��㷽����ʱ�䣺%lfs\n", (double(stop) - double(start))/CLK_TCK);

	start = clock();
	for (int i = 0; i < MaxTimes; i++)
	{
		DirectDuo(n, a, x);
	}
	stop = clock();
	printf("  ֱ�Ӽ���ķ�����ʱ�䣺%lfs\n", (double(stop) - double(start))/CLK_TCK);
	return 0;
}