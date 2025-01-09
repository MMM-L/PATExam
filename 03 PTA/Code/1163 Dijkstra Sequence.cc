#include<iostream>
#include<vector>
using namespace std;

const int MAX_NV = 1001;  // ����ͼ����
const int MAX_K = 100;    // �����Ե�
const int MAX_DIST = 0x7FFFFFFF;

struct Node {
  int v;
  int w;
  Node(int _v, int _w) : v(_v), w(_w){};
};
vector<Node> G[MAX_NV];       // ͼ
vector<int> list_seq[MAX_K];  // ����·��
int Nv = 0, Ne = 0;           // ͼ�Ķ���ͱ�����

bool IsDijkstraSequence(int i) {
  int start = list_seq[i][0];
  int dist[MAX_NV] = {0};       // ��ǰ��̾���
  bool vist[MAX_NV] = {false};  // ���ʱ�־

  fill(dist + 1, dist + Nv + 1, MAX_DIST);  // �����е����start��Ϊ������
  dist[start] = 0;

  // �ҵ����е����start�����̾���
  // ��������ͼ�����ж���
  int list_u = 0;
  for (int j = 0; j < Nv; ++j) {
    list_u = list_seq[i][j];

    int u = -1;
    int max_dist = MAX_DIST;
    // step1���ҵ�����start��Ŀǰ�����δ�����ʹ���һ����
    for (int i = 1; i <= Nv; ++i) {
      if (dist[i] < max_dist && !vist[i]) {
        u = i;
        max_dist = dist[i];
      }
    }
    if (dist[list_u] != max_dist) {
      return false;
    }

    if (u == -1) {  // ͼ�����ж����Ѿ��������ˣ����ߴ�ʱû�����ӵ�
      continue;
    }
    vist[u] = true;  // ��Ǳ�������

    for (int k = 0; k < G[u].size(); ++k) {
      int v = G[u][k].v;
      int w = G[u][k].w;
      if (dist[u] + w <= dist[v] && !vist[v]) {
        dist[v] = dist[u] + w;  // ������̾���
      }
    }
  }
  return true;
}

int main() {

  // ����ͼ
  scanf_s("%d %d", &Nv, &Ne);
  for (int i = 0; i < Ne; ++i) {
    int temp_u = 0, temp_v = 0, temp_w = 0;
    scanf_s("%d %d %d", &temp_u, &temp_v, &temp_w);
    G[temp_u].push_back(Node(temp_v, temp_w));  // ����Ϊ����ͼ
    G[temp_v].push_back(Node(temp_u, temp_w));
  }

  // ������԰���
  int example = 0;
  scanf_s("%d", &example);
  for (int i = 0; i < example; ++i) {
    int temp;
    for (int j = 0; j < Nv; ++j) {  // ȫ������
      scanf_s("%d", &temp);
      list_seq[i].push_back(temp);
    }
  }
  
  // ��ʼ�ж��Ƿ���dijkstra sequence
  for (int i = 0; i < example; ++i) {
    if (IsDijkstraSequence(i)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;
}
