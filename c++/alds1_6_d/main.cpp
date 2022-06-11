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

  cout << "A" << endl;
  printVector(A);
  cout << "sortedA" << endl;
  printVector(sortedA);

  std::map<int, int> aiToIndex;
  for (int i = 0; i < A.size(); i++) {
    aiToIndex[A[i]] = i;
  }
  cout << "aiToIndex" << endl;
  printMap(aiToIndex);

  std::map<int, int> sortedAiToIndex;
  for (int i = 0; i < sortedA.size(); i++){
    sortedAiToIndex[sortedA[i]] = i;
  }
  cout << "sortedAiToIndex" << endl;
  printMap(sortedAiToIndex);

  int minimumIndex = 0;
  int swapCount = 0;
  while (minimumIndex < A.size())
  {
    int mimumAi = sortedA[minimumIndex];
    int mimumAiCurrentIndex = aiToIndex[mimumAi];
    cout << "mimumAi:" << mimumAi << endl;
    cout << "mimumAiCurrentIndex: " << mimumAiCurrentIndex << endl;

    if (mimumAiCurrentIndex == sortedAiToIndex[mimumAi]) {
      cout << "swapCount: " << swapCount << endl;
      int swapConstByCurrentMini = sortedA[mimumAiCurrentIndex] * swapCount;
      int swapCostByMini = sortedA[0] * swapCount + (sortedA[mimumAiCurrentIndex] + sortedA[0]) * 2;
      cout << "swapConst by current mini: " << swapConstByCurrentMini << endl;
      cout << "swapCost by mini: " << swapCostByMini << endl;
      if (swapConstByCurrentMini > swapCostByMini) {
        // cout << "must use mini " << swapConstByCurrentMini - swapCostByMini << endl;
        cost = cost - swapConstByCurrentMini + swapCostByMini;
      }
      else
      {
        cout << "not use mini " << swapConstByCurrentMini - swapCostByMini << endl;
      }

      minimumIndex++;
      swapCount = 0;

      continue;
    }

    int target = sortedA[mimumAiCurrentIndex];
    int targetCurrentIndex = aiToIndex[target];

    cost += A[mimumAiCurrentIndex] + A[targetCurrentIndex];
    swap(A[mimumAiCurrentIndex], A[targetCurrentIndex]);
    swap(aiToIndex[A[mimumAiCurrentIndex]], aiToIndex[A[targetCurrentIndex]]);
    swapCount = swapCount + 1;
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
