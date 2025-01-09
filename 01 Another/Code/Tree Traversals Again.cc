#include<iostream>
#include<string>
#include<stack>
using namespace std;

// ���������־
bool flag = false;

// ���Ľ��
typedef struct TreeNode* Tree;
struct TreeNode {
  string data;
  Tree left{};
  Tree right{};
};


Tree Init();
Tree CreatNode();
void PostTraversed(Tree root);


int main() {
  Tree root{};
  root = Init();
  PostTraversed(root);
  return 0;
}

// ��ʼ��������һ����
Tree Init() {
  Tree root{}, node{}, temp{};
  stack<Tree> sta{};
  string str{};  // ������string��Ƚϼ򵥣����Ŀ찡��
  int N{};
  cin >> N;
  cin.get();
  if (!N) {
    return root;
  } else {
    root = CreatNode();
  }
  node = root;
  for (int i = 0; i < 2 * N; i++) {
    getline(cin, str);
    if (str == "Pop") {
      node = sta.top();
      sta.pop();
    } else {  // �����push
      temp = CreatNode();
      temp->data = str.substr(5);
      if (!node->left) {
        node->left = temp;
      } else if (!node->right) {
        node->right = temp;
      }
      node = temp;
      sta.push(temp);
    }
  }
  temp = root;
  root = root->left;
  delete temp;
  return root;
}

// ����һ�����Ľ��
Tree CreatNode() {
  // ���ڽṹ������string����
  // ��Ҫ��new�������ڴ�
  Tree temp = new struct TreeNode();
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

// �������һ����
void PostTraversed(Tree root) {
  if (!root) {
    return;
  }
  PostTraversed(root->left);
  PostTraversed(root->right);
  if (flag) {
    cout << ' ';
  } else {
    flag = true;
  }
  cout << root->data;
  return;
}
