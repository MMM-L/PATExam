// �����ֲ�ͬ�ķ��������0-N������
// MMM, 2023.01.09
#include<stdio.h>


// ����һ��ѭ�����
void printN(int N)
{
	for (int i = 0; i <= N; i++)
	{
		printf("%d\n", i);
	}
}

// ���������ݹ����
// ����������Ƚϼ�࣬���ǻ����Ľϴ�Ŀռ�
void IrPrintN(int N)
{
	if (N >= 0)
	{
		IrPrintN(N-1);
		printf("%d\n", N);
	}
}


int main()
{
	int N = 0;
	printf("Please enter N = ");
	scanf_s("%d", &N);
	printf("ѭ������Ľ��\n");
	printN(N);
	printf("�ݹ�����Ľ��\n");
	IrPrintN(N);
	return 0;
}