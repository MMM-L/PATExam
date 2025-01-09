#include<iostream>
#include<vector>
using namespace std;

vector<int> Graph[100];
int State[100]{0};  // ����������״̬ { 0 1 2 }
bool flag{false};

// ������ȱ���
void DFS(int Nv) {
  if (State[Nv] == 1) {  // �л�
    flag = true;
    return;  // �ж��л�ֱ�ӷ��أ������ڷ�����������ˡ�
  }
  State[Nv] = 1;  // ���ڷ��ʸö���
  for (int i = 0; i < Graph[Nv].size(); i++) {
    if (State[Graph[Nv][i]] != 2) {  // ����û�б�������Ķ���
      DFS(Graph[Nv][i]);
    }
  }
  State[Nv] = 2;  // �ö���������
}

void VistGraph(int n) {
  for (int i = 0; i < n; i++) {
    if (State[i] != 2) {  // ����û�б�������Ķ���
      DFS(i);
    }
  }
}

int main() {
  int n{}, m{};

  // ����ͼ�Ķ���ͱߵ�����
  cin >> n >> m;

  // ��������ͼ
  for (int i = 0; i < m; ++i) {
    int temp1{}, temp2{};
    cin >> temp1 >> temp2;
    Graph[temp1].push_back(temp2);
  }
  VistGraph(n);  // ��ȱ���ͼGraph
  if (flag) {    // ����ͼ����ѭ��ͼ��������
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
} 
