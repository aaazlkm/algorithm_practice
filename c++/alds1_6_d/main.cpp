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

int quick(vector<int> &A, int start, int end){
  int thresholdIndex = end;
  int threshold = A[thresholdIndex];
  int i = start-1;
  for(int j = start; j < end; j++){
    if (A[j] <= threshold) {
      i++;
      swap(A[i], A[j]);
    }
  }

  i++;
  swap(A[i], A[thresholdIndex]);

  return i;
}

void quickSort(vector<int> &A, int start, int end){
  if (start < end) {
    int a = quick(A, start, end);
    quickSort(A, start, a - 1);
    quickSort(A, a + 1, end);
  }
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }

  vector<int> sortedA = A;
  quickSort(sortedA, 0, A.size() - 1);
  printVector(A);
  printVector(sortedA);

  return 0;
}
