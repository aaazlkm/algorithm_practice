#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> countingSort(vector<int> A, int k) {
  vector<int> C(k, 0);
  for (int i = 0; i < A.size(); i++) {
    C[A[i]]++;
  }
  for (int i = 1; i < k; i++) {
    C[i] += C[i - 1];
  }

  vector<int> result(A.size());
  for (int i = A.size()-1; i >= 0; i--)
  {
    result[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }
  return result;
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int k = 10000;
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }

  vector<int> sorted = countingSort(A, k);

  for (int i = 0; i < n; i++)
  {
    cout << sorted[i];
    if (i == n - 1)
    {
      cout << endl;
    }
    else
    {
      cout << " ";
    }
  }

  return 0;
}
