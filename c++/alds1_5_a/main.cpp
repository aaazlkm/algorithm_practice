#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool add(vector<int> a, int i,int sum, int m) {
  if (sum > m ) {
    return false;
  }
  if (sum == m) {
    return true;
  }
  if (a.size() == i) {
    return sum == m;
  }
  bool whenUse = add(a, i + 1, sum + a[i], m);
  if (whenUse) {
    return true;
  }
  bool whenNoUse = add(a, i + 1, sum, m);
  if (whenNoUse) {
    return true;
  }
  return false;
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    int value;
    cin >> value;
    a[i] = value;
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int m;
    cin >> m;
    if (add(a, 0, 0, m))
    {
      cout << "yes" << endl;
    }
    else
    {
      cout << "no" << endl;
    }
  }

  return 0;
}
