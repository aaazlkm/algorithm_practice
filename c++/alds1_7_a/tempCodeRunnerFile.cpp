#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printVector(vector<int> A)
{
  for (int i = 0; i < A.size(); i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}

void printMap(map<int, vector<int>> map)
{
  for (const auto &item : map)
  {
    for(int i = 0; i < item.second.size(); i++) {
      cout << item.second[i] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

struct Node
{
  int nodeId;
  vector<Node> parents;
  vector<Node> children;

  bool isRoot() {
    if (parents.size() == 0)
    {
      return false;
    }
    return parents[0].nodeId == -1;
  }

  bool isLeaf() {
    return children.size() == 0;
  }

  bool isInternalNode()
  {
    return children.size() != 0;
  }

  int childrenCount() {
    return children.size();
  }

  int calculateDepth(int depth) {
    if (parents.size() == 0) {
      return depth;
    }
    Node parent = parents[0];
    if (parent.nodeId == -1)
    {
      return depth;
    }

    depth = depth + 1;
    return parent.calculateDepth(depth);
  }

  void printNodeInfo() {
    cout << "node " << nodeId << ": ";
    cout << "parent = " << parents[0].nodeId << ", ";
    cout << "depth = " << calculateDepth(0) << ", ";

    if (isRoot()){
      cout << "root,";
    }else if (isLeaf()) {
      cout << "leaf,";
    }
    else if (isInternalNode())
    {
      cout << "internal node,";
    }
    cout << " ";

    cout << "[";
    for (int i = 0; i < children.size(); i++) {
      if (i == children.size() - 1)
     {
       cout << children[i].nodeId;
      }
      else
      {
        cout << children[i].nodeId << ", ";
      }
    }
    cout << "]";
    cout << endl;

    for (int i = 0; i < children.size(); i++) {
      children[i].printNodeInfo();
    }
  }
};

int searchRootNode(map<int, vector<int>> nodeToChildren)
{
  set<int> set;
  for (const auto &item : nodeToChildren)
  {
    int nodeId = item.first;
    vector<int> children = item.second;
    for (int i = 0; i < children.size(); i++) {
      set.insert(children[i]);
    }
  }

  for (const auto &item : nodeToChildren)
  {
    int nodeId = item.first;
    if (set.find(nodeId) == set.end()) {
      return nodeId;
    }
  }
  throw invalid_argument("");
}

Node createNode(int nodeId, Node parent, map<int, vector<int>> nodeToChildren)
{
  struct Node node;
  node.nodeId = nodeId;
  node.parents.push_back(parent);

  vector<int> childrenIds = nodeToChildren[nodeId];
  vector<Node> children;
  for (int i = 0; i < childrenIds.size(); i++) {
    int childId = childrenIds[i];
    children.push_back(createNode(childId, node, nodeToChildren));
  }
  node.children = children;
  return node;
}

Node createTree(map<int, vector<int>> nodeToChildren)
{
  struct Node node;
  node.nodeId = -1;

  struct Node rootNode;
  rootNode.nodeId = searchRootNode(nodeToChildren);
  rootNode.parents.push_back(node);
  vector<int> childrenIds = nodeToChildren[rootNode.nodeId];
  vector<Node> children;
  for (int i = 0; i < childrenIds.size(); i++)
  {
    int childId = childrenIds[i];
    children.push_back(createNode(childId, rootNode, nodeToChildren));
  }
  rootNode.children = children;
  return rootNode;
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  map<int, vector<int>> nodeToChildren = {};

  for (int i = 0; i < n; i++)
  {
    int nodeId, k;
    cin >> nodeId >> k;
    vector<int> children(k);
    for (int j = 0; j < k; j++)
    {
      cin >> children[j];
    }
    nodeToChildren[nodeId] = children;
  }

  Node tree = createTree(nodeToChildren);
  tree.printNodeInfo();

  return 0;
}
