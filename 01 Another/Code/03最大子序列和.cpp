// ������к����⣬��ƶ���㷨����������Ƚϸ��Ӷ�
// ��ʵ���ﻹ����һ�������ӵ����⣬��ΰ����������и���ȡ����
// ����һ��ÿ��������ŵ�����ʱ��


#include<stdio.h>
#include<time.h>


// ����ĸ���
#define N 13
// �������������ֵ
#define Max3(A, B, C) (A > B ? (A > C ? A : C) : (B > C ? B : C))


// ����һ��ֱ�ӽ��б�������ٷ�
// ʱ�临�Ӷ�ΪO(n^3)
int MaxSubseqSum1(int List[])
{
	int MaxSum, ThisSum;
	MaxSum = 0;
	for (int i = 0; i < N; i++)/*���������ײ�*/
	{
		for (int j = i; j < N; j++)/*��������β��*/
		{
			ThisSum = 0;/*��ʼ�����е�ÿ������*/
			for (int k = i; k <= j; k++)
			{
				ThisSum += List[k];
			}
			if (ThisSum > MaxSum)/*����������к�*/
			{
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}


// ���������ڼ������е�ʱ�򣬲���ÿ�ζ�����
// ʱ�临�Ӷ�O(n^2)
int MaxSubseqSum2(int List[])
{
	int MaxSum, ThisSum;
	MaxSum = 0;
	for (int i = 0; i < N; i++)/*���������ײ�*/
	{
		ThisSum = 0;/*��ʼ�����е�ÿ������*/
		for (int j = i; j < N; j++)/*��������β��*/
		{
			ThisSum += List[j];
			if (ThisSum > MaxSum)/*����������к�*/
			{
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}


// ����������һ�ֱ�����ʽ
int MaxSubseqSum2_2(int List[])
{
	int MaxSum = 0, ThisSum = 0, Sum[N] = { 0 };
	Sum[0] = List[0];
	for (int i = 1; i < N; i++)/*����ÿ�����еĺ�*/
	{
		Sum[i] = Sum[i-1] + List[i];
	}
	for (int i = 0; i < N; i++)
	{
		ThisSum = Sum[i];
		for (int j = 0; j <= i; j++)/*�����е��ײ��𽥵ĵݼ�*/
		{
			if (ThisSum > MaxSum)
			{
				MaxSum = ThisSum;
			}
			ThisSum -= List[j];/*�������һ����Ϊ0��*/
		}
	}
	return MaxSum;
}


// ���������ֶ���֮���������⻮��ΪС���⣬�����������
// �����е��ࣨ�㲻��ͼ�ֲ���ȥ�˰ɣ���
// ʱ�临�Ӷ�O(nlogn)
int HalfSlove(int List[], int Left, int Right)
{
	// �������������Ľ�
	int MaxLeftSum = 0, MaxRightSum = 0;
	// ��ſ�ֽ��ߵĵĽ�
	int MaxLeftBorderSum = 0, MaxRightBorderSum = 0;
	int LeftBorderSum = 0, RightBorderSum = 0;
	int Center = 0;
	Center = (Left + Right) / 2;

	// �ݹ����ֹ����
	// ��ʱ���о�ֻ��һ����ֵ
	if (Left == Right)
	{
		if (List[Left] <= 0)
		{
			return 0;
		}
		else
		{
			return List[Left];
		}
	}

	// ��ʼ���зֵĹ��̣��ݹ�����徿����ʲô
	// �����е����ֵ
	MaxLeftSum = HalfSlove(List, Left, Center);

	// �����е����ֵ
	MaxRightSum = HalfSlove(List, Center + 1, Right);

	// ��ֽ��ߵ����ֵ
	for (int i = Center; i >= Left; i--)
	{
		LeftBorderSum += List[i];
		if (LeftBorderSum > MaxLeftBorderSum)
		{
			MaxLeftBorderSum = LeftBorderSum;
		}
	}
	for (int i = Center + 1; i <= Right; i++)
	{
		RightBorderSum += List[i];
		if (RightBorderSum > MaxRightBorderSum)
		{
			MaxRightBorderSum = RightBorderSum;
		}
	}

	// �ѷֿ������������
	// Ҫ�ȽϵĶ������ֵ����������˺ܾ�
	return Max3(MaxLeftSum, MaxRightSum, (MaxRightBorderSum + MaxLeftBorderSum));
}


// ���ֺ���������һ���ĸ�ʽ
int MaxSubseqSum3(int List[])
{
	return HalfSlove(List, 0, N - 1);
}


// �����ģ����ߴ���"̰���㷨"
// �����еĺ�Ϊ������ʱ��, ֱ�Ӿ�������������ڵ�ǰ�����ֵ�͸���
int MaxSubseqSum4(int List[])
{
	int ThisSum = 0, MaxSum = 0;
	for (int i = 0; i < N; i++)
	{
		ThisSum += List[i];
		if (ThisSum > MaxSum)/*�ж����ֵ�Ƿ����*/
		{
			MaxSum = ThisSum;
		}
		else if (ThisSum < 0)/*�жϵ�ǰ�������Ƿ�С��0*/
		{
			ThisSum = 0;
		}
	}
	return MaxSum;
}


int main()
{
	int List[N] = { 2,-5,3,1,4,-2,5,-1,-2,6,3,-1,-1};
	int MaxSum = 0;
	MaxSum = MaxSubseqSum1(List);
	printf("1�������к�Ϊ��%d\n", MaxSum);
	MaxSum = MaxSubseqSum2(List);
	printf("2�������к�Ϊ��%d\n", MaxSum);
	MaxSum = MaxSubseqSum2_2(List);
	printf("2_2�������к�Ϊ��%d\n", MaxSum);
	MaxSum = MaxSubseqSum3(List);
	printf("3�������к�Ϊ��%d\n", MaxSum);
	MaxSum = MaxSubseqSum4(List);
	printf("4�������к�Ϊ��%d\n", MaxSum);
	return 0;
}

