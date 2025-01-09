// ��ҵ�ľ���Ҫ��
// https://pintia.cn/problem-sets/15/exam/problems/923

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode* List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
// ʵ�ֶ��ַ��Ĳ��ң���Ե�����������أ�
// �ǵݹ�ʵ��
//Position BinarySearch(List L, ElementType X)
//{
//    Position Left, Right, Center;
//    Left = 1;
//    Right = L->Last;
//    while (Left <= Right)
//    {
//        Center = (Left + Right) / 2;
//        if (X < L->Data[Center])
//        {
//            Right = Center - 1;
//        }
//        else if (X > L->Data[Center])
//        {
//            Left = Center + 1;
//        }
//        else
//        {
//            return Center;
//        }
//    }
//    return NotFound;
//}


/* ��Ĵ��뽫��Ƕ������ */
// ʵ�ֶ��ַ��Ĳ��ң���Ե�����������أ�
// �ݹ�ʵ��
Position BinarySearch(List L, ElementType X)
{
    return Search(L, X, 1, L->Last);
}

Position Search(List L, ElementType X, Position Left, Position Right)
{
    Position Center;
    Center = (Left + Right) / 2;
    if (Left > Right)
    {
        return NotFound;
    }

    if (X < L->Data[Center])
    {
        return Search(L, X, Left, Center - 1);
    }
    else if (X > L->Data[Center])
    {
        return Search(L, X, Center + 1, Right);
    }
    else
        return Center;
}