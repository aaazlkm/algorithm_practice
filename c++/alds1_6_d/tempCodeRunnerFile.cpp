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

void printMap(map<int, int> map)
{
  for (const auto &item : map)
  {
    cout << "[" << item.first << "," << item.second << "] ";
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

  // cout << "A" << endl;
  // printVector(A);
  // cout << "sortedA" << endl;
  // printVector(sortedA);

  std::map<int, int> aiToIndex;
  for (int i = 0; i < A.size(); i++) {
    aiToIndex[A[i]] = i;
  }
  // cout << "aiToIndex" << endl;
  // printMap(aiToIndex);

  std::map<int, int> sortedAiToIndex;
  for (int i = 0; i < sortedA.size(); i++){
    sortedAiToIndex[sortedA[i]] = i;
  }
  // cout << "sortedAiToIndex" << endl;
  // printMap(sortedAiToIndex);

  int minimumIndex = 0;
  while (minimumIndex < A.size())
  {
    int mimumAi = sortedA[minimumIndex];
    int mimumAiCurrentIndex = aiToIndex[mimumAi];
    // cout << "mimumAi:" << mimumAi << endl;
    // cout << "mimumAiCurrentIndex: " << mimumAiCurrentIndex << endl;

    if (mimumAiCurrentIndex == sortedAiToIndex[mimumAi]) {
      minimumIndex++;
      continue;
    }

    int target = sortedA[mimumAiCurrentIndex];
    int targetIndex = aiToIndex[target];

    cost += A[mimumAiCurrentIndex] + A[targetIndex];
    swap(A[mimumAiCurrentIndex], A[targetIndex]);
    swap(aiToIndex[A[mimumAiCurrentIndex]], aiToIndex[A[targetIndex]]);
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
