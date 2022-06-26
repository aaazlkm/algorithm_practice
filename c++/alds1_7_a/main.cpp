#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int NIL = -1;

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
  node.id = NIL;
  node.parentId = NIL;
  node.childId = NIL;
  node.siblingId = NIL;
  node.depth = NIL;
}

int calculateDepth(Node node, map<int, Node> &nodeIdToNode)
{
  if (node.depth != NIL)
  {
    return node.depth;
  }

  if (node.parentId == NIL)
  {
    nodeIdToNode[node.id].depth = 0;
    return 0;
  }

  int parentDepth = calculateDepth(nodeIdToNode[node.parentId], nodeIdToNode);
  nodeIdToNode[node.id].depth = parentDepth + 1;
  return nodeIdToNode[node.id].depth;
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

void printChildInfo(int childId, vector<Node> nodes)
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
      printChildInfo(child.siblingId, nodes);
    }
  }
}

void printNodeInfo(int nodeId, vector<Node> &nodes)
{
  Node node = nodes[nodeId];
  string type = buildNodeType(node);
  cout << "node " << node.id << ": parent = " << node.parentId << ", depth = " << node.depth << ", " << type << ", [";
  printChildInfo(node.childId, nodes);
  cout << "]" << endl;
}

void setDepth(int nodeId, vector<Node> nodes, int depth) {
  nodes[nodeId].depth = depth;
  if (nodes[nodeId].childId != NIL) {
    setDepth(nodes[nodeId].childId, nodes, depth + 1);
  }
  if (nodes[nodeId].siblingId != NIL) {
    setDepth(nodes[nodeId].siblingId, nodes, depth);
  }
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<Node> nodes(n);
  for (int i = 0; i < n; i++) {
    struct Node node;
    initNode(node);
    cout << "node " << node.parentId << ": ";
    nodes.push_back(node);
    cout << "parentId " << nodes[0].parentId << ": ";
    cout << "nodeID " << nodes[0].id << ": ";
  }
  cout << "parentId " << nodes[0].parentId << ": ";

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
      cout << "childId " << childId << ": ";
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

  cout << "debug 1" << endl;

  int rootNodeId = NIL;
  for (int i = 0; i < n; i++) {
    if (nodes[i].parentId == NIL) {
      cout << "debug 33 " << nodes[i].id << " " << nodes[i].parentId << endl;
      rootNodeId = nodes[i].id;
      break;
    }
    cout << "id to parent " << nodes[i].id << " to " << nodes[i].parentId << endl;
  }

  cout << "debug 2 " << rootNodeId <<  endl;

  setDepth(rootNodeId, nodes, 0);

  cout << "debug 3" << endl;

  for (int i = 0; i < n; i++) {
    printNodeInfo(i, nodes);
  }

  return 0;
}
