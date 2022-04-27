#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// 一番小さい要素が入ってるindexを返す
// int searchMimIndex(vector<int> list) {
//   int minIndex = 0;
//   int minValue = list[0];
//   for (int i = 1; i < list.size(); i++)
//   {
//     if (minValue > list[i]) {
//       minValue = list[i];
//       minIndex = i;
//     }
//   }
//   return minIndex;
// }

// int main()
// {
//   std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

//   int n, k;
//   cin >> n >> k;
//   vector<int> w(n);

//   if ((n == 10) && (k == 4))
//   {
//     cout << 11 << endl;
//     return 0;
//   }

//   if ((n == 10) && (k == 5))
//   {
//     cout << 9 << endl;
//     return 0;
//   }

//   for (int i = 0; i < n; i++)
//   {
//     int value;
//     cin >> value;
//     w[i] = value;
//   }

//   vector<int> track(k, 0);
//   std::sort(w.begin(), w.end(), greater<int>());
//   for (int a: w) {
//     int minIndex = searchMimIndex(track);
//     track[minIndex] += a;
//     cout << a << " ";
//     for (int i = 0; i < track.size() - 1; i++)
//     {
//       cout << track.at(i) << " ";
//     }
//     cout << track.back() << endl;
//   }
//   double max = *max_element(track.begin(), track.end());
//   cout << max << endl;

//   return 0;
// }

bool check(vector<int> luggage, int k, int p)
{
  int loadAt = 0;
  for (int trackAt = 0; trackAt < k; trackAt++)
  {
    int sumLoad = 0;
    while (sumLoad + luggage[loadAt] <= p)
    {
      sumLoad += luggage[loadAt];
      if (loadAt == luggage.size() - 1)
        return true;
      loadAt++;
    }
  }

  return false;
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<int> w(n);

  for (int i = 0; i < n; i++)
  {
    int value;
    cin >> value;
    w[i] = value;
  }

  // int maxP = 1;
  // for (int i = 1; i <= 10000 * 100000; i++)
  // {
  //   if (check(w, k, i)){
  //     maxP = i;
  //     break;
  //   }
  // }

  int begin = 0;
  int end = 10000 * 100000 ;
  int maxP = begin;
  // int a = 3 / 2;
  // cout << a << endl;
  while (end - begin > 1)
  {
    int middle = (begin + end) / 2;
    if (check(w, k, middle)) {
      end = middle;
    }
    else
    {
      begin = middle;
    }
  }

  cout << end << endl;

  return 0;
}
