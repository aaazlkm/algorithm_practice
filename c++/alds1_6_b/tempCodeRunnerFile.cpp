#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int myPartition(vector<int>& A, int n) {
  if (n <= 1) {
    return n;
  }
  int i = -1;
  int threshold = A[n - 1];
  for (int j = 0; j < n; j++)
  {
    if (A[j] <= threshold)
    {
      i++;
      swap(A[i], A[j]);
    }
  }
  i++;
  swap(A[i], A[n - 1]);
  return i;
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int q = myPartition(A, n);

  for (int i = 0; i < n; i++) {
    if (i == q) {
      cout << "[" << A[i] << "]";
    } else {
      cout << A[i];
    }

    if (i == n-1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
