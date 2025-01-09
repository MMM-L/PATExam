// ����007_simple
//  https://pintia.cn/problem-sets/16/exam/problems/type/7?problemSetProblemId=672&page=0
// 2024.05.18
// =========================================

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double diameter = 15;  // С��ֱ��
const double edgeDist = 50;  // ��Ե����

// crocodiles vertex
struct Vertex {
  int x;
  int y;
  bool flag;  // wheather visit?
  Vertex(int _x, int _y, bool _flag = false) : x(_x), y(_y), flag(_flag){};
};

struct Graph {
  int maxStep;  // the most distance he can access
  vector<Vertex> data;
  explicit Graph(int _maxStep) : maxStep(_maxStep){};
};

Graph* BuildGraph();
bool saveJamesBond(Graph* graph0);
bool accessNext(Vertex start, Vertex dest, double maxStep);
bool DFS(Graph* graph0, Vertex start);

// build graph
Graph* BuildGraph() { 
  int NumCrocodiles{};
  int maxStep{};
  cin >> NumCrocodiles >> maxStep;

  Graph* graph0 = new Graph(maxStep);
  
  int x{}, y{};
  for (int i{}; i < NumCrocodiles; ++i) {
    cin >> x >> y;
    graph0->data.push_back(Vertex(x, y));
    //graph0->data.emplace_back(x, y);
  }
  return graph0;
}

// 
bool saveJamesBond(Graph* graph0) { 
  int maxStep = graph0->maxStep;  // James Bond max Step

  // ��һ���ڵ�λ�ã���Ȼ�Ѿ����ʹ��ˣ�
  Vertex start(0, 0, true);

  // ����ÿ���ڵ�λ�ö���Ҫ���ж����Ƿ��ܹ�ֱ������ȥ
  if (maxStep + diameter / 2 >= edgeDist) {
    return true;
  }

  // ���жϵ�һ������Ϊ��С���ϣ����Բ�̫��ͳһ
  // ��ʼ��2���Ժ󣬽��������������
  for (int i = 0; i < graph0->data.size(); ++i) {
    if ((!graph0->data[i].flag) && accessNext(start, graph0->data[i], diameter/2 + maxStep)) {
      // ��ʼ�������
      graph0->data[i].flag = true;
      if (DFS(graph0, graph0->data[i])) {
        return true;
      }
    }
  }
  return false;
}

// �����ڵ��ܷ񵽴�
bool accessNext(Vertex start, Vertex dest, double maxStep) {
  return (pow(start.x - dest.x, 2) + pow(start.y - dest.y, 2)) <= pow(maxStep, 2);
}

//
bool DFS(Graph* graph0, Vertex start) {
  int maxStep = graph0->maxStep;

  // ���ж������start�ܷ�ֱ������ȥ
  if ((start.x + maxStep >= edgeDist)  || 
      (start.x - maxStep <= -edgeDist) ||
      (start.y + maxStep >= edgeDist)  || 
      (start.y - maxStep <= -edgeDist)) {
    return true;
  }

  // �������������
  for (int i = 0; i < graph0->data.size(); ++i) {
    if ((!graph0->data[i].flag) && accessNext(start, graph0->data[i], maxStep)) {
      // ��ʼ�������
      graph0->data[i].flag = true;
      if (DFS(graph0, graph0->data[i])) {
        return true;
      }
    }
  }
  return false;
}

// main
int main(int argc, char* argv[]) {
  // step1:
  Graph* graph0 = BuildGraph();

  // step2:
  if (saveJamesBond(graph0)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
