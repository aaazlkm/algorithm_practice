#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int NIL = -1;
const int MAX = 100005;

struct Node
{
  int id;
  int parentId;
  int leftId;
  int rightId;
};

Node nodes[MAX];

void initNode(Node &node)
{
  node.id = NIL;
  node.parentId = NIL;
  node.leftId = NIL;
  node.rightId = NIL;
}

void printTreeInfoByPreorder(int nodeId) {
  Node node = nodes[nodeId];
  cout << " " << nodeId;
  if (node.leftId != NIL)
  {
    printTreeInfoByPreorder(node.leftId);
  }
  if (node.rightId != NIL)
  {
    printTreeInfoByPreorder(node.rightId);
  }
}

void printTreeInfoByInorder(int nodeId)
{
  Node node = nodes[nodeId];
  if (node.leftId != NIL)
  {
    printTreeInfoByInorder(node.leftId);
  }
  cout << " " << nodeId;
  if (node.rightId != NIL)
  {
    printTreeInfoByInorder(node.rightId);
  }
}

void printTreeInfoByPostOrder(int nodeId)
{
  Node node = nodes[nodeId];
  if (node.leftId != NIL)
  {
    printTreeInfoByPostOrder(node.leftId);
  }
  if (node.rightId != NIL)
  {
    printTreeInfoByPostOrder(node.rightId);
  }
  cout << " " << nodeId;
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    struct Node node;
    nodes[i] = node;
    initNode(nodes[i]);
  }

  for (int i = 0; i < n; i++)
  {
    int nodeId, leftId, rightId;
    cin >> nodeId >> leftId >> rightId;
    nodes[nodeId].id = nodeId;
    nodes[nodeId].leftId = leftId;
    nodes[nodeId].rightId = rightId;

    if (leftId != NIL)
    {
      nodes[leftId].parentId = nodeId;
    }

    if (rightId != NIL)
    {
      nodes[rightId].parentId = nodeId;
    }
  }

  int rootNodeId = NIL;
  for (int i = 0; i < n; i++) {
    if (nodes[i].parentId == NIL) {
      rootNodeId = nodes[i].id;
      break;
    }
  }

  cout << "Preorder" << endl;
  printTreeInfoByPreorder(rootNodeId);
  cout << endl;

  cout << "Inorder" << endl;
  printTreeInfoByInorder(rootNodeId);
  cout << endl;

  cout << "Postorder" << endl;
  printTreeInfoByPostOrder(rootNodeId);
  cout << endl;

  return 0;
}
