// �г���ͨ��
// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=714&page=0\
// ===============================================

#include <iostream>
#include <queue>
using namespace std;

// 
const int N_max = 10;  // ��󶥵���
int graph0[N_max][N_max]{};
int flag[N_max]{};
int N_num{}, Edge_num{};

//
void DFS(int start);
void BFS(int start);

//
int main(int argc, char* argv[]) {
  cin >> N_num >> Edge_num;
  
  int u_tmp{}, v_tmp{};
  for (int i = 0; i < Edge_num; ++i) {
    cin >> u_tmp >> v_tmp;
    graph0[u_tmp][v_tmp] = 1;
    graph0[v_tmp][u_tmp] = 1;
  }

  // �г�DFS��ͨ��
  fill(flag, flag + N_num, 0);
  for (int i = 0; i < N_num; ++i) {
    if (!flag[i]) {
      cout << '{';
      DFS(i);
      cout << " }" << endl;
    }
  }

  // �г�BFS��ͨ��
  fill(flag, flag + N_num, 0);
  for (int i = 0; i < N_num; ++i) {
    if (!flag[i]) {
      cout << '{';
      BFS(i);
      cout << " }" << endl;
    }
  }
  return 0;
}

// 
void DFS(int start) {
  cout << ' '<< start;
  flag[start] = 1;
  for (int i = 0; i < N_num; ++i) {
    if (!flag[i] && graph0[start][i] == 1) {
      DFS(i);
    }
  }
}

//
void BFS(int start) {
  queue<int> q_bfs;  // ���뿴����������Լ���дһ�����п�����
  q_bfs.push(start);
  flag[start] = 1;
  while (!q_bfs.empty()) {
    int u_tmp = q_bfs.front();
    cout << ' ' << u_tmp;
    q_bfs.pop();
    for (int i = 0; i < N_num; ++i) {
      if (!flag[i] && graph0[u_tmp][i] == 1) {
        q_bfs.push(i);
        flag[i] = 1;
      }
    }
  }
}





















