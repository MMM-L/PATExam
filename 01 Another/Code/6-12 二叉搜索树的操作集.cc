BinTree Insert(BinTree BST, ElementType X) {
  // �����������Ĳ������
  if (BST == NULL) {
    BST = (BinTree)malloc(sizeof(struct TNode));
    BST->Data = X;
    // ע��һ��Ҫ������������ΪNULL
    BST->Left = NULL;
    BST->Right = NULL;
  }
  if (BST->Data < X) {  // ���뵽��������
    BST->Right = Insert(BST->Right, X);
  } else if (BST->Data > X) {  // ���뵽��������
    BST->Left = Insert(BST->Left, X);
  }
  return BST;
}

BinTree Delete(BinTree BST, ElementType X) {
  // ������������ɾ������
  BinTree temp;
  if (BST == NULL) {
    printf("Not Found\n");
  } else {
    if (BST->Data < X) {
      BST->Right = Delete(BST->Right, X);
    } else if (BST->Data > X) {
      BST->Left = Delete(BST->Left, X);
    } else {  // �ҵ���Ҫɾ���Ľ��
      if (BST->Left && BST->Right) {
        temp = FindMax(BST->Left);
        BST->Data = temp->Data;
        BST->Left = Delete(BST->Left, BST->Data);
      } else {
        temp = BST;
        if (BST->Left == NULL) {
          BST = BST->Right;
        } else {
          BST = BST->Left;
        }
        free(temp);
      }
    }
  }
  return BST;
}

Position Find(BinTree BST, ElementType X) {
  // �����������Ĳ���
  if (BST == NULL) {
    return NULL;
  } else {
    if (BST->Data < X) {
      return Find(BST->Right, X);
    } else if (BST->Data > X) {
      return Find(BST->Left, X);
    } else {  // �ҵ���
      return BST;
    }
  }
}

Position FindMin(BinTree BST) {
  // ����������������СԪ��
  // ע����Ҫ���ǿ��������
  if (BST == NULL) {
    return NULL;
  }
  if (BST->Left == NULL) {
    return BST;
  } else {
    return FindMin(BST->Left);
  }
}

Position FindMax(BinTree BST) {
  // ���Ҷ��������������Ԫ��
  // ע����Ҫ���ǿ��������
  if (BST == NULL) {
    return NULL;
  }
  if (BST->Right == NULL) {
    return BST;
  } else {
    return FindMax(BST->Right);
  }
}
