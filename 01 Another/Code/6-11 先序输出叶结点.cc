//void PreorderPrintLeaves(BinTree BT) {
//  int temp_left_flag = 0, temp_right_flag = 0;
//  if (BT) {  // ������н��
//    if (BT->Left) {
//      PreorderPrintLeaves(BT->Left);
//      temp_left_flag = 1;
//    }
//
//    if (BT->Right) {
//      PreorderPrintLeaves(BT->Right);
//      temp_right_flag = 1;
//    }
//
//    if (!(temp_left_flag || temp_right_flag)) {  // ��û���ӽ����
//      printf(" %c", BT->Data);
//    }
//  }
//  return;
//}


// ��д��̫�����ˡ�����
// ��������д�Ķ��ࣿ��
void PreorderPrintLeaves(BinTree BT) {
  if (BT == NULL) {
    return;
  }

  if (BT->Left == NULL && BT->Right == NULL) {
    printf(" %c", BT->Data);
  }

  PreorderPrintLeaves(BT->Left);
  PreorderPrintLeaves(BT->Right);
}
