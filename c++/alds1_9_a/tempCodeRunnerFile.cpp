#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int NIL = -1;
const int MAX = 100005;

void printVector(vector<int> A)
{
  for (int i = 0; i < A.size(); i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}

struct Node
{
  int id;
  int leftId;
  int rightId;
};

Node nodes[MAX];

void initNode(Node &node)
{
  node.id = NIL;
  node.leftId = NIL;
  node.rightId = NIL;
}

void restoreNode(int nodeId, vector<int> *preOrder, vector<int> inOrder) {
  vector<int> leftIds;
  vector<int> rightIds;

  bool isLeft = true;
  for (int i = 0; i < inOrder.size(); i++)
  {
    int nodeIdInOrder = inOrder[i];
    if (nodeIdInOrder == nodeId) {
      isLeft = false;
      continue;
    }
    if (isLeft)
      {
        leftIds.push_back(nodeIdInOrder);
      } else {
        rightIds.push_back(nodeIdInOrder);
    }
  }

  nodes[nodeId].id = nodeId;
  if (leftIds.size() > 0)
  {
    int nextNodeId = preOrder->operator[](0);
    preOrder->erase(preOrder->begin());
    nodes[nodeId].leftId = nextNodeId;
    nodes[nextNodeId].id = nextNodeId;
    nodes[nextNodeId].leftId = NIL;
    nodes[nextNodeId].rightId = NIL;
    if (leftIds.size() > 1) {
      restoreNode(nextNodeId, preOrder, leftIds);
    }
  }
  if (rightIds.size() > 0) {
    int nextNodeId = preOrder->operator[](0);
    preOrder->erase(preOrder->begin());
    nodes[nodeId].rightId = nextNodeId;
    nodes[nextNodeId].id = nextNodeId;
    nodes[nextNodeId].leftId = NIL;
    nodes[nextNodeId].rightId = NIL;

    if (rightIds.size() > 1)
    {
      restoreNode(nextNodeId, preOrder, rightIds);
    }
  }
}

void printNodeByPostOrder(int nodeId, bool isRoot) {
  if (nodes[nodeId].leftId != NIL) {
    printNodeByPostOrder(nodes[nodeId].leftId, false);
  }
  if (nodes[nodeId].rightId != NIL) {
    printNodeByPostOrder(nodes[nodeId].rightId, false);
  }

  if (isRoot) {
    cout << nodes[nodeId].id << endl;
  } else {
    cout << nodes[nodeId].id << " ";
  }
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    struct Node node;
    initNode(node);
    nodes[i] = node;
  }

  vector<int> preOrder(n);
  for (int i = 0; i < n; i++)
  {
    cin >> preOrder[i];
  }

  vector<int> inOrder(n);
  for (int i = 0; i < n; i++)
  {
    cin >> inOrder[i];
  }

  int rootNodeId = preOrder[0];
  preOrder.erase(preOrder.begin());

  restoreNode(rootNodeId, &preOrder, inOrder);

  printNodeByPostOrder(rootNodeId, true);

  return 0;
}
