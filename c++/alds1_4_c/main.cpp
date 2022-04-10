#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct input
{
  string operation;
  string value;
};

int main()
{
  int n;
  cin >> n;
  input inputs[n];
  set<string> set;

  for (int i = 0; i < n; i++)
  {
    string operation, value;
    cin >> operation >> value;
    struct input input;
    input.operation = operation;
    input.value = value;
    inputs[i] = input;
  }

  for (int i = 0; i < n; i++)
  {
    input input = inputs[i];
    string operation = input.operation;
    string value = input.value;
    if (operation == "insert")
    {
      set.insert(value);
    }
    else if (operation == "find")
    {
      if (set.count(value) != 0)
      {
        cout << "yes" << endl;
      }
      else
      {
        cout << "no" << endl;
      }
    }
  }

  return 0;
}
