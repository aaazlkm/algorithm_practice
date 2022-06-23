// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// void printVector(vector<int> A)
// {
//   for (int i = 0; i < A.size(); i++)
//   {
//     cout << A[i] << " ";
//   }
//   cout << endl;
// }

// void printMap(map<int, vector<int>> map)
// {
//   for (const auto &item : map)
//   {
//     for(int i = 0; i < item.second.size(); i++) {
//       cout << item.second[i] << " ";
//     }
//     cout << endl;
//   }
//   cout << endl;
// }

// struct Node
// {
//   int nodeId;
//   vector<Node> parents;
//   vector<Node> children;
//   int depth;

//   bool isRoot() {
//     if (parents.size() == 0)
//     {
//       return false;
//     }
//     return parents[0].nodeId == -1;
//   }

//   bool isLeaf() {
//     return children.size() == 0;
//   }

//   bool isInternalNode()
//   {
//     return children.size() != 0;
//   }

//   int childrenCount() {
//     return children.size();
//   }

//   int calculateDepth(int depth) {
//     if (!this->depth) {
//       return this->depth + depth;
//     }

//     if (parents.size() == 0) {
//       return depth;
//     }
//     Node parent = parents[0];
//     if (parent.nodeId == -1)
//     {
//       return depth;
//     }

//     depth = depth + 1;
//     int calulatedDepth = parent.calculateDepth(depth);
//     this->depth = calulatedDepth;
//     return calulatedDepth;
//   }

//   void printNodeInfo(map<int, string> &nodeIdToInfo) {
//     char buff[100];
//     string type;
//     if (isRoot())
//     {
//       type = "root";
//     }
//     else if (isLeaf())
//     {
//       type = "leaf";
//     }
//     else if (isInternalNode())
//     {
//       type = "internal node";
//     }

//     string childrenString = "";
//     for (int i = 0; i < children.size(); i++)
//     {
//       if (i == children.size() - 1)
//       {
//         childrenString += to_string(children[i].nodeId);
//       }
//       else
//       {
//         childrenString += to_string(children[i].nodeId);
//         childrenString += ", ";
//       }
//     }

//     sprintf(buff, "node %d: parent = %d, depth = %d, %s, [%s]", this->nodeId, parents[0].nodeId, calculateDepth(0), type.c_str(), childrenString.c_str());

//     nodeIdToInfo[nodeId] = string(buff);
//     for (int i = 0; i < children.size(); i++)
//     {
//       children[i].printNodeInfo(nodeIdToInfo);
//     }
//   }
// };

// int searchRootNode(map<int, vector<int>> nodeToChildren, set<int> childrenNodeId)
// {
//   for (const auto &item : nodeToChildren)
//   {
//     int nodeId = item.first;
//     if (childrenNodeId.find(nodeId) == childrenNodeId.end())
//     {
//       return nodeId;
//     }
//   }
//   throw invalid_argument("");
// }

// Node createNode(int nodeId, Node parent, map<int, vector<int>> nodeToChildren)
// {
//   struct Node node;
//   node.nodeId = nodeId;
//   node.parents.push_back(parent);

//   vector<int> childrenIds = nodeToChildren[nodeId];
//   vector<Node> children;
//   for (int i = 0; i < childrenIds.size(); i++) {
//     int childId = childrenIds[i];
//     children.push_back(createNode(childId, node, nodeToChildren));
//   }
//   node.children = children;
//   return node;
// }

// Node createTree(map<int, vector<int>> nodeToChildren, set<int> childrenNodeId)
// {
//   struct Node node;
//   node.nodeId = -1;

//   struct Node rootNode;
//   rootNode.nodeId = searchRootNode(nodeToChildren, childrenNodeId);
//   rootNode.parents.push_back(node);
//   vector<int> childrenIds = nodeToChildren[rootNode.nodeId];
//   vector<Node> children;
//   for (int i = 0; i < childrenIds.size(); i++)
//   {
//     int childId = childrenIds[i];
//     children.push_back(createNode(childId, rootNode, nodeToChildren));
//   }
//   rootNode.children = children;
//   return rootNode;
// }

// int main()
// {
//   std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

//   int n;
//   cin >> n;
//   map<int, vector<int>> nodeToChildren = {};
//   set<int> childrenNodeId;

//   for (int i = 0; i < n; i++)
//   {
//     int nodeId, k;
//     cin >> nodeId >> k;
//     vector<int> children(k);
//     for (int j = 0; j < k; j++)
//     {
//       cin >> children[j];
//       childrenNodeId.insert(children[j]);
//     }
//     nodeToChildren[nodeId] = children;
//   }

//   Node tree = createTree(nodeToChildren, childrenNodeId);

//   map<int, string> nodeIdToInfo = {};
//   tree.printNodeInfo(nodeIdToInfo);

//   for (const auto &item : nodeToChildren)
//   {
//     cout << nodeIdToInfo[item.first] << endl;
//   }

//   return 0;
// }

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
    for (int i = 0; i < item.second.size(); i++)
    {
      cout << item.second[i] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

struct Node
{
  int id;
  int parent;
  int child;
  int sibling;
  int depth;
};


int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  map<int, Node> nodeIdToNode;
  vector<Node> nodes;

  for (int i = 0; i < n; i++)
  {
    int nodeId, k;
    cin >> nodeId >> k;
    vector<int> children(k);
    for (int j = 0; j < k; j++)
    {
      int childId;
      cin >> childId;
      child.parent = nodeId;
    }
    nodeToChildren[nodeId] = children;
  }

  Node tree = createTree(nodeToChildren, childrenNodeId);

  map<int, string> nodeIdToInfo = {};
  tree.printNodeInfo(nodeIdToInfo);

  for (const auto &item : nodeToChildren)
  {
    cout << nodeIdToInfo[item.first] << endl;
  }

  return 0;
}
