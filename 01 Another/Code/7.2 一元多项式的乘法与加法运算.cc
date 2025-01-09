#include <iostream>
using namespace std;
struct Poly {
  int coefficient;  // ϵ��
  int index;        // ָ��
  struct Poly* next;
};
// �������ʽ
Poly* InputPoly() {
  int n = 0;
  Poly* p1, * p2, * temp;
  p1 = (Poly*)malloc(sizeof(struct Poly));
  //p2->coefficient = 0;
  //p2->index = 0;
  //p2->next = NULL;
  //p1 = p2;
  p2 = p1;
  cin >> n;  // ����ʽ���������
  for (int i = 0; i < n; ++i) {
    temp = (Poly*)malloc(sizeof(struct Poly));
    cin >> temp->coefficient;
    cin >> temp->index;
    p2->next = temp;  // ���½��Ľ���������β��
    p2 = p2->next;    // p2ʼ��ָ������β��
    //if (++i < n) {  // ����ں����������Ļ�����һ���õ��ϡ�
    //                // ������ͷ�����һ���ս�㣬Ȼ�����ͷŵ���
    //  p2->next = (Poly *)malloc(sizeof(struct Poly));
    //  p2 = p2->next;
    //}
  }
  p2->next = NULL;
  temp = p1;
  p1 = p1->next;
  free(temp);
  return p1;
}
// �������ʽ
void OutputPoly(Poly* p) {
  if (!p) {
    cout << "0 0";
  }
  // �������ʽ�����ϵ����ָ��
  while (p) {
    cout << p->coefficient << ' ';
    if (p->next) {
      cout << p->index << ' ';
    }
    else {
      cout << p->index;
    }
    p = p->next;
  }
  cout << endl;
  return;
}
// ��������ʽ�ļӷ�
Poly* PolyAdd(Poly* p1, Poly* p2) {
  Poly* ps, * rear, * temp;
  ps = (Poly*)malloc(sizeof(struct Poly));
  rear = ps;
  // һ��һ��ļ�
  while (p1 && p2) {
    if (p1->index == p2->index) {  /*��������ʽ��ָ��һ��*/
      // ע�⣡
      // ������Ҫ����ϵ��Ϊ0������������ϲ�ͬ���
      if (p1->coefficient + p2->coefficient == 0) {
        p1 = p1->next;
        p2 = p2->next;
        continue;
      }
      // ����һ���µĽ��
      // �洢��ǰ�ļ�����
      temp = (Poly*)malloc(sizeof(struct Poly));
      temp->coefficient = p1->coefficient + p2->coefficient;
      temp->index = p1->index;
      // ���˽����뵽����ʽ��ĩβ
      rear->next = temp;
      rear = rear->next;
      p1 = p1->next;
      p2 = p2->next;
    } else if (p1->index < p2->index) {  /*ָ����Ķ���ʽ�����ƶ�һ��*/
      // ����һ���µĽ��
      // �洢��ǰָ���������
      temp = (Poly *)malloc(sizeof(struct Poly));
      temp->coefficient = p2->coefficient;
      temp->index = p2->index;
      // ���˽����뵽����ʽ��ĩβ
      rear->next = temp;
      rear = rear->next;
      p2 = p2->next;
    } else {  /*p1->index > p2->index*/
      // ����һ���µĽ��
      // �洢��ǰָ���������
      temp = (Poly *)malloc(sizeof(struct Poly));
      temp->coefficient = p1->coefficient;
      temp->index = p1->index;
      // ���˽����뵽����ʽ��ĩβ
      rear->next = temp;
      rear = rear->next;
      p1 = p1->next;
    }
  }
  // �������ʽ����ʣ�����ӵ��������ʽ�ĺ���
  while (p1) {
    // ����һ���µĽ��
    // �洢��ǰʣ������
    temp = (Poly *)malloc(sizeof(struct Poly));
    temp->coefficient = p1->coefficient;
    temp->index = p1->index;
    // ���˽����뵽����ʽ��ĩβ
    rear->next = temp;
    rear = rear->next;
    p1 = p1->next;
  }
  while (p2) {
    // ����һ���µĽ��
    // �洢��ǰʣ������
    temp = (Poly *)malloc(sizeof(struct Poly));
    temp->coefficient = p2->coefficient;
    temp->index = p2->index;
    // ���˽����뵽����ʽ��ĩβ
    rear->next = temp;
    rear = rear->next;
    p2 = p2->next;
  }
  rear->next = NULL;
  temp = ps;
  ps = ps->next;
  free(temp);
  return ps;
}
// ��������ʽ�ĳ˷�
// ����ת��Ϊ�ӷ����������
Poly *PolyMul(Poly *p1, Poly *p2) {
  Poly *pm, *temp;
  pm = NULL;
  // һ����ļ���ȥ
  for (Poly *pi = p1; pi != NULL; pi = pi->next) {
    for (Poly *pj = p2; pj != NULL; pj = pj->next) {
      temp = (Poly *)malloc(sizeof(struct Poly));
      // ������������ƣ����ﲻ����Ϊ0�����ÿ��Ǻϲ�ͬ����
      temp->coefficient = pi->coefficient * pj->coefficient;
      temp->index = pi->index + pj->index;
      temp->next = NULL;
      pm = PolyAdd(pm, temp);
    }
  }
  return pm;
}
int main() {
  Poly *p1, *p2, *pm, *ps;
  // ������������ʽ
  p1 = InputPoly();
  p2 = InputPoly();
  // ��������ʽ���
  pm = PolyMul(p1, p2);
  // ��������ʽ���
  ps = PolyAdd(p1, p2);
  // �����������ʽ�������Ľ��
  OutputPoly(pm);
  OutputPoly(ps);
  return 0;
}
