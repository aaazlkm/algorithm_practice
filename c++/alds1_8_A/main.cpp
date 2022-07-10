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
  int value = NIL;
  Node* parent = nullptr;
  Node* left = nullptr;
  Node* right = nullptr;
};

void insert(Node tree, Node nodeToInsert)
{
  Node* current = &tree;
  while (current->value != NIL)
  {
    if (nodeToInsert.value < current->value)
    {
      current = current->left;
    } else {
      current = current->right;
    }
  }
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  struct Node root;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    string operation;
    int value;
    cin >> operation;
    if (operation == "insert")
    {
      cin >> value;
      struct Node node;
      node.value = value;
      insert(root, node);
    }
    else if (operation == "print")
    {
      // TODO print
    }
  }
  return 0;
}
