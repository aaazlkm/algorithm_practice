#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int NIL = -1;
const int MAX = 100005;

struct Node
{
  int id;
  int parentId;
  int childId;
  int siblingId;
  int depth;
};

Node nodes[MAX];

void initNode(Node &node)
{
  node.id = NIL;
  node.parentId = NIL;
  node.childId = NIL;
  node.siblingId = NIL;
  node.depth = NIL;
}

string buildNodeType(Node node)
{
  string type;
  if (node.parentId == NIL)
  {
    type = "root";
  }
  else if (node.childId == NIL)
  {
    type = "leaf";
  }
  else if (node.childId != NIL)
  {
    type = "internal node";
  }
  return type;
}

void printChildInfo(int childId)
{
  if (childId == NIL)
  {
    return;
  }
  else
  {
    Node child = nodes[childId];
    cout << to_string(child.id);
    if (child.siblingId != NIL)
    {
      cout << ", ";
      printChildInfo(child.siblingId);
    }
  }
}

void printNodeInfo(int nodeId)
{
  Node node = nodes[nodeId];
  string type = buildNodeType(node);
  cout << "node " << node.id << ": parent = " << node.parentId << ", depth = " << node.depth << ", " << type << ", [";
  printChildInfo(node.childId);
  cout << "]" << endl;
}

void setDepth(int nodeId, int depth) {
  nodes[nodeId].depth = depth;
  if (nodes[nodeId].childId != NIL) {
    setDepth(nodes[nodeId].childId, depth + 1);
  }
  if (nodes[nodeId].siblingId != NIL) {
    setDepth(nodes[nodeId].siblingId, depth);
  }
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
    int nodeId, childrenSize;
    cin >> nodeId >> childrenSize;
    nodes[nodeId].id = nodeId;
    int prevNodeId;
    for (int j = 0; j < childrenSize; j++)
    {
      int childId;
      cin >> childId;

      nodes[childId].id = childId;
      nodes[childId].parentId = nodeId;

      if (j == 0)
      {
        nodes[nodeId].childId = childId;
      } else {
        nodes[prevNodeId].siblingId = childId;
      }
      prevNodeId = childId;
    }
  }

  int rootNodeId = NIL;
  for (int i = 0; i < n; i++) {
    if (nodes[i].parentId == NIL) {
      rootNodeId = nodes[i].id;
      break;
    }
  }

  setDepth(rootNodeId, 0);

  for (int i = 0; i < n; i++) {
    printNodeInfo(i);
  }

  return 0;
}
