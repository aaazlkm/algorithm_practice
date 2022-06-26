#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int NOT_SET = -1;

struct Node
{
  int id;
  int parentId;
  int childId;
  int siblingId;
  int depth;
};

void initNode(Node &node)
{
  node.id = NOT_SET;
  node.parentId = NOT_SET;
  node.childId = NOT_SET;
  node.siblingId = NOT_SET;
  node.depth = NOT_SET;
}

int calculateDepth(Node node, map<int, Node> &nodeIdToNode)
{
  if (node.depth != NOT_SET)
  {
    return node.depth;
  }

  if (node.parentId == NOT_SET)
  {
    nodeIdToNode[node.id].depth = 0;
    return 0;
  }

  int parentDepth = calculateDepth(nodeIdToNode[node.parentId], nodeIdToNode);
  nodeIdToNode[node.id].depth = parentDepth + 1;
  return nodeIdToNode[node.id].depth;
}

string buildNodeType(Node node, map<int, Node> nodeIdToNode)
{
  string type;
  if (node.parentId == NOT_SET)
  {
    type = "root";
  }
  else if (node.childId == NOT_SET)
  {
    type = "leaf";
  }
  else if (node.childId != NOT_SET)
  {
    type = "internal node";
  }
  return type;
}

void printChildInfo(int childId, map<int, Node> nodeIdToNode)
{
  if (childId == NOT_SET)
  {
    return;
  }
  else
  {
    Node child = nodeIdToNode[childId];
    cout << to_string(child.id);
    if (child.siblingId != NOT_SET)
    {
      cout << ", ";
      printChildInfo(child.siblingId, nodeIdToNode);
    }
  }
}

void printNodeInfo(int nodeId, map<int, Node> &nodeIdToNode)
{
  Node node = nodeIdToNode[nodeId];
  string type = buildNodeType(node, nodeIdToNode);
  cout << "node " << node.id << ": parent = " << node.parentId << ", depth = " << calculateDepth(node, nodeIdToNode) << ", " << type << ", [";
  printChildInfo(node.childId, nodeIdToNode);
  cout << "]" << endl;
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  map<int, Node> nodeIdToNode;

  for (int i = 0; i < n; i++)
  {
    int nodeId, k;
    cin >> nodeId >> k;
    struct Node node;
    if (nodeIdToNode.find(nodeId) == nodeIdToNode.end())
    {
      initNode(node);
      node.id = nodeId;
    }
    else
    {
      node = nodeIdToNode[nodeId];
    }
    int prevNodeId;
    for (int j = 0; j < k; j++)
    {
      int childId;
      cin >> childId;
      struct Node child;
      if (nodeIdToNode.find(childId) == nodeIdToNode.end())
      {
        initNode(child);
        child.id = childId;
      }
      else
      {
        child = nodeIdToNode[childId];
      }
      child.parentId = nodeId;

      if (j == 0)
      {
        node.childId = child.id;
      } else {
        nodeIdToNode[prevNodeId].siblingId = child.id;
      }

      prevNodeId = child.id;
      nodeIdToNode[child.id] = child;
    }
    nodeIdToNode[nodeId] = node;
  }

  for (const auto &item : nodeIdToNode)
  {
    printNodeInfo(item.first, nodeIdToNode);
  }

  return 0;
}
