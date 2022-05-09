#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int mergeCompareCount = 0;

void merge(vector<int>& A, int left, int middle, int right) {
  int n1 = middle - left;
  int n2 = right - middle;
  vector<int> L = vector<int>(n1 + 1);
  vector<int> R = vector<int>(n2 + 1);
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[middle + i];
  }
  L[n1] = 2147483647;
  R[n2] = 2147483647;
  int i = 0;
  int j = 0;
  // 二つに分けた配列のうち、より小さい方をAの配列に入れるようにしてる
  for (int k = left; k < right; k++)
  {
    mergeCompareCount++;
    if (L[i] <= R[j])
    {
      A[k] = L[i];
      i++;
    }
    else
    {
      A[k] = R[j];
      j++;
    }
  }
  // cout << "============== " << left  << " ==============" << endl;
  // cout << "left: ";
  // for (auto v : L)
  // {
  //   cout << v << " ";
  // }
  // cout << endl;

  // cout << "right: ";
  // for (auto v : R)
  // {
  //   cout << v << " ";
  // }
  // cout << endl;

  // for (auto v : A)
  // {
  //   cout << v << " ";
  // }
  // cout << endl;
}

void mergeSort(vector<int>& A, int left, int right)
{
  if (left + 1 < right)
  {
    int middle = (left + right) / 2;
    mergeSort(A, left, middle);
    mergeSort(A, middle, right);
    merge(A, left, middle, right);
  }
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> w(n);

  for (int i = 0; i < n; i++)
  {
    cin >> w[i];
  }

  mergeSort(w, 0, n);

  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      cout << w[i] << endl;
    } else {
      cout << w[i] << " ";
    }
  }

  cout << mergeCompareCount << endl;

  return 0;
}
