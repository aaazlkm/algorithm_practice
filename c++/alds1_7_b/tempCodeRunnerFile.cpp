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
  int depth;
  int height;
};

Node nodes[MAX];

void initNode(Node &node)
{
  node.id = NIL;
  node.parentId = NIL;
  node.leftId = NIL;
  node.rightId = NIL;
  node.depth = NIL;
  node.height = NIL;
}

string buildDegree(Node node)
{
  if (node.leftId != NIL && node.rightId != NIL) {
    return "2";
  }
  else if (node.leftId != NIL || node.rightId != NIL)
  {
    return "1";
  }
  else
  {
    return "0";
  }
}

string buildNodeType(Node node)
{
  string type;
  if (node.parentId == NIL)
  {
    type = "root";
  }
  else if (node.leftId == NIL || node.rightId == NIL)
  {
    type = "leaf";
  }
  else
  {
    type = "internal node";
  }
  return type;
}

string buildSibling(Node node) {
  if (node.parentId == NIL)
  {
    return "-1";
  }
  else if (node.parentId != NIL)
  {
    Node parent = nodes[node.parentId];
    if (parent.leftId == node.id)
    {
      return to_string(parent.rightId);
    }
    else if (parent.rightId == node.id)
    {
      return to_string(parent.leftId);
    }
  }
  return "-1";
}

void printNodeInfo(int nodeId)
{
  Node node = nodes[nodeId];
  string sibling = buildSibling(node);
  string degree = buildDegree(node);
  string type = buildNodeType(node);

  cout << "node " << node.id << ": parent = " << node.parentId << ", "
       << "sibling = " << sibling << ", "
       << "degree = " << degree << ", "
       << "depth = " << node.depth << ", "
       << "height = " << node.height << ", "
       << type << endl;
}

void setDepth(int nodeId, int depth) {
  nodes[nodeId].depth = depth;
  if (nodes[nodeId].leftId != NIL) {
    setDepth(nodes[nodeId].leftId, depth + 1);
  }
  if (nodes[nodeId].rightId != NIL) {
    setDepth(nodes[nodeId].rightId, depth + 1);
  }
}

int setHeight(int nodeId) {
  int leftHeight = NIL;
  int rightHeight = NIL;
  if (nodes[nodeId].leftId != NIL)
  {
    leftHeight = setHeight(nodes[nodeId].leftId);
  }
  if (nodes[nodeId].rightId != NIL) {
    rightHeight = setHeight(nodes[nodeId].rightId);
  }

  int height;
  if (leftHeight != NIL && rightHeight != NIL) {
    height = max(leftHeight, rightHeight) + 1;
    nodes[nodeId].height = height;
  } else if (leftHeight != NIL) {
    height = leftHeight + 1;
    nodes[nodeId].height = height;
  } else if (rightHeight != NIL) {
    height = rightHeight + 1;
    nodes[nodeId].height = height;
  } else {
    height = 0;
    nodes[nodeId].height = height;
  }
  return height;
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

    if (rightId != NIL) {
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

  setDepth(rootNodeId, 0);
  setHeight(rootNodeId);

  for (int i = 0; i < n; i++) {
    printNodeInfo(i);
  }

  return 0;
}
