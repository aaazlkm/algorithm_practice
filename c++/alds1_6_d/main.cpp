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

int countCost(vector<int> A) {
  int cost = 0;
  vector<int> sortedA = A;
  quickSort(sortedA, 0, A.size() - 1);
  // printVector(A);
  // printVector(sortedA);
  std::map<int, int> aiToIndex;
  for (int i = 0; i < A.size(); i++) {
    aiToIndex[A[i]] = i
  }

  std::map<int, int> sortedAiToIndex;
  for (int i = 0; i < sortedA.size(); i++){
    sortedAiToIndex[A[i]] = i
  }


  for (int i = 0; i < sortedA.size(); i++) {
    int mimumAi = sortedA[i];
    int mimumAiIndex = aiToIndex[mimumAi];

    int future = sortedA[mimumAiIndex];
    int currentIndex = aiToIndex[future];

    cost += A[mimumAiIndex] + A[currentIndex];
    swap(A[mimumAiIndex], A[currentIndex])
    // mapも入れ替える
  }

  return cost;
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

  int cost = countCost(A);
  cout << cost << endl;
  return 0;
}
