Stack CreateStack(int MaxSize) {
  // ��̵�����˶�̬����Ľ���
  Stack newstack = (Stack)malloc(sizeof(struct SNode));
  newstack->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
  newstack->Top1 = -1;
  newstack->Top2 = MaxSize;
  newstack->MaxSize = MaxSize;
  return newstack;
}
// ��ջ����
bool Push(Stack S, ElementType X, int Tag) {
  // �ж�ջ�ռ��Ƿ�������
  if (S->Top1 == S->Top2 - 1) {  // ջ�ռ�����
    printf("Stack Full\n");
    return false;
  }
  if (Tag == 1) {
    S->Data[S->Top1 + 1] = X;
    ++S->Top1;
  } else if (Tag == 2) {
    S->Data[S->Top2 - 1] = X;
    --S->Top2;
  }
  return true;
}
// ��������
ElementType Pop(Stack S, int Tag) {
  // ���ж϶�ջ�Ƿ�Ϊ��
  if (Tag == 1) {
    if (S->Top1 > -1) {
      --S->Top1;
      return S->Data[S->Top1 + 1];
    } else {
      printf("Stack %d Empty\n", Tag);
      return ERROR;
    }
  } else if (Tag == 2) {
    if (S->Top2 < S->MaxSize) {
      ++S->Top2;
      return S->Data[S->Top2 - 1];
    } else {
      printf("Stack %d Empty\n", Tag);
      return ERROR;
    }
  }
}