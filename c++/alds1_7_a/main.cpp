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
    cout << "[" << item.first << "," << item.second[0] << "] ";
  }
  cout << endl;
}

struct Card
{
  int nodeId;
  int number;
};

struct Node
{
  int nodeId;
  Node parent;
  vector<Node> children;

  int childrenCount() {
    return children.size();
  }
};

Node createTree(map<int, vector<int>> nodeToChildren) {

}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  map<int, vector<int>> nodeToChildren;
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

  printMap(nodeToChildren);

  return 0;
}
