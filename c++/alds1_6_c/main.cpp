#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Card
{
  string type;
  int number;
};

int myPartition(vector<Card> &A, int p, int r)
{
  int i = p - 1;
  int threshold = A[r].number;
  for (int j = p; j < r; j++)
  {

    if (A[j].number <= threshold)
    {
      i++;
      swap(A[i], A[j]);
    }
  }
  i++;
  swap(A[i], A[r]);
  return i;
}

void quickSort(vector<Card> &A, int p, int r)
{
  if (p < r)
  {
    int q = myPartition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<Card> A(n);
  map<int, vector<string>> map{};
  for (int i = 0; i < n; i++)
  {
    struct Card card;
    cin >> card.type >> card.number;
    A[i] = card;
    map[card.number].push_back(card.type);
  }

  quickSort(A, 0, n-1);

  bool isStable = true;
  int i = 0;
  while(i < n) {
    vector<string> types = map[A[i].number];
    for (int j = 0; j < types.size(); j++) {
      if (types[j] == A[i].type)
      {
        i++;
      }
      else {
        isStable = false;
        break;
      }
    }
    if(!isStable) {
      break;
    }
  }
  if (isStable) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }

  for (int i = 0; i < n; i++) {
    cout << A[i].type << " "<< A[i].number << endl;
  }

  return 0;
}
