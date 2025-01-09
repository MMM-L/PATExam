// ����Ԫ��ѭ����������

#include<iostream>
using namespace std;

// ����һ���������
//int main()
//{
//    int a[100] = { 0 };
//    int N = 0, M = 0;
//    cin >> N;  // ����ĸ���
//    cin >> M;  // �ƶ��ĸ���
//    for (int i = 0; i < N; i++)
//    {
//        cin >> a[i];
//    }
//
//    // ���ǵ�M����N�����
//    M %= N;
//    for (int i = N - M; i < N; i++)
//    {
//        cout << a[i];
//        cout << ' ';
//    }
//    for (int i = 0; i < N - M; i++)
//    {
//        cout << a[i];
//        if (i < N - M - 1)
//            cout << ' ';
//    }
//    return 0;
//}


// ��������һ�������ƶ�
//int main()
//{
//    int a[100] = { 0 };
//    int N = 0, M = 0, tem = 0;
//    cin >> N;  // ����ĸ���
//    cin >> M;  // �ƶ��ĸ���
//    for (int i = 0; i < N; i++)
//    {
//        cin >> a[i];
//    }
//
//    // ���ǵ�M����N�����
//    M %= N;
//
//    // ѭ����������
//    for (int i = 0; i < M; i++)
//    {
//        tem = a[N - 1];
//        for (int j = 0; j < N - 1; j++)
//        {
//            a[N - 1 - j] = a[N - 2 - j];
//        }
//        a[0] = tem;
//    }
//
//    // ��ӡ�ƶ���������
//    for (int i = 0; i < N; i++)
//    {
//        cout << a[i];
//        if (i < N - 1)
//        {
//            cout << ' ';
//        }
//    }
//    return 0;
//}


// �����������鷴ת
void Swap(int* a, int* b)
{
	// ���á�����߼������н���
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int main()
{
    int a[100] = { 0 };
    int N = 0, M = 0;
    cin >> N;  // ����ĸ���
    cin >> M;  // �ƶ��ĸ���
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    // ��M��N��
    M %= N;
    // ���ȷ�ת��������
    for (int i = 0, j = N - 1; i < j; i++, j--)
    {
        Swap(&a[i], &a[j]);
    }

    // Ȼ��תǰM��
    for (int i = 0, j = M - 1; i < j; i++, j--)
    {
        Swap(&a[i], &a[j]);
    }

    // �ڷ�ת��N-M��
    for (int i = M, j = N - 1; i < j; i++, j--)
    {
        Swap(&a[i], &a[j]);
    }

    // ��ӡ�ƶ���������
    for (int i = 0; i < N; i++)
    {
        cout << a[i];
        if (i < N - 1)
        {
            cout << ' ';
        }
    }

	return 0;
}
