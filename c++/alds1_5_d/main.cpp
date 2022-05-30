#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct resultValue
{ // Declare a local structure
  vector<int> list;
  int index;
};

void printVector(vector<int> A)
{
  for (int i = 0; i < A.size(); i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}

// マージソートベース
// MLEで失敗する
// resultValue myPartition(vector<int> A, int p, int r, int &count)
// {
//   int thresholdIndex = p;
//   int threshold = A[thresholdIndex];
//   int i = p;
//   vector<int> below;
//   vector<int> above;
//   for (int j = p + 1; j <= r; j++)
//   {

//     if (A[j] <= threshold)
//     {
//       below.push_back(A[j]);
//       count += above.size();
//       i++;
//     } else {
//       above.push_back(A[j]);
//     }
//   }

//   count += below.size();
//   vector<int> result;
//   for (int i = 0; i < p; i++)
//   {
//     result.push_back(A[i]);
//   }
//   result.insert(result.end(), below.begin(), below.end());
//   result.push_back(threshold);
//   result.insert(result.end(), above.begin(), above.end());
//   for (int i = r + 1; i < A.size(); i++)
//   {
//     result.push_back(A[i]);
//   }

//   // printVector(A);
//   // printVector(below);
//   // printVector(above);
//   // printVector(result);
//   // cout << count << endl;

//   return resultValue {result, i};
// }

// クリックソートベース
// int myPartition(vector<int> &A, int p, int r, int &count)
// {
//   // cout << "========" << endl;

//   int thresholdIndex = p;
//   int threshold = A[thresholdIndex];
//   int i = p;
//   for (int j = p + 1; j <= r; j++)
//   {

//     if (A[j] <= threshold)
//     {
//       count += (j - 1) - i;
//       // if ((j - 1) - i != 0) {
//       //   cout << A[j] << ":" << (j - 1) - i  << endl;
//       // }
//       i++;
//       // swap(A[j], A[i]);
//       // for (int k = j; k > i; k--)
//       // {
//       //   swap(A[k], A[k-1]);
//       // }

//       int tempJ = A[j];
//       A.insert(A.begin() + i + 1, A[i]);
//       A.erase(A.begin() + i);
//       A.erase(A.begin() + j);
//       A.insert(A.begin() + i, tempJ);
//       // printVector(A);
//     }
//   }

//   A.insert(A.begin() + i + 1, threshold);
//   A.erase(A.begin() + thresholdIndex);

//   // // 順番を崩さないように移動してる
//   // for (int j = thresholdIndex; j < i; j++){
//   //   swap(A[j], A[j + 1]);
//   // }
//   // swap(A[i], A[thresholdIndex]);
//   count += i - p;
//   // printVector(A);
//   // cout << count << endl;
//   return i;
// }

// 真ん中のものを使用してクイックソートベース
// TLEだった
// int myPartition(vector<int> &A, int p, int r, int &count)
// {
//   // cout << "========" << endl;

//   int thresholdIndex = (p + r)/2;
//   // cout << thresholdIndex << " " << p << " " << r << endl;
//   // printVector(A);

//   int threshold = A[thresholdIndex];

//   // cout << "before: ";
//   // printVector(A);

//   A.erase(A.begin() + thresholdIndex);
//   A.insert(A.begin() + p, threshold);

//   // cout << "after: ";
//   // printVector(A);

//   int i = p;
//   for (int j = p + 1; j <= r; j++)
//   {

//     if (A[j] <= threshold)
//     {
//       if (thresholdIndex < j)
//       {
//         // threholdが元々いた位置のケア
//         count++;
//       }
//       //jのものをiに持ってく時のカウント
//       count += (j - 1) - i;
//       // if ((j - 1) - i != 0) {
//       //   cout << A[j] << ":" << (j - 1) - i  << endl;
//       // }
//       i++;
//       // swap(A[j], A[i]);
//       // for (int k = j; k > i; k--)
//       // {
//       //   swap(A[k], A[k-1]);
//       // }

//       int tempJ = A[j];
//       A.insert(A.begin() + i + 1, A[i]);
//       A.erase(A.begin() + i);
//       A.erase(A.begin() + j);
//       A.insert(A.begin() + i, tempJ);
//       // printVector(A);
//     } else {
//       // 元々thresholdがいた位置より手前で、thresholdより大きいものを数える
//       // thresholdを移動させた時のcountを入れるため
//       if (j <= thresholdIndex)
//       {
//         count++;
//       }
//     }
//   }

//   A.insert(A.begin() + i + 1, threshold);
//   A.erase(A.begin() + p);

//   // cout << "final: ";
//   // printVector(A);

//   // cout << count << endl;

//   // // 順番を崩さないように移動してる
//   // for (int j = thresholdIndex; j < i; j++){
//   //   swap(A[j], A[j + 1]);
//   // }
//   // swap(A[i], A[thresholdIndex]);
//   // count += i - p;
//   // printVector(A);
//   // cout << count << endl;
//   return i;
// }

// // void countNumberOfInversions(vector<int> A, int p, int r, int &count)
// // {
// //   if (p < r) {
// //     resultValue result = myPartition(A, p, r, count);
// //     countNumberOfInversions(result.list, p, result.index - 1, count);
// //     countNumberOfInversions(result.list, result.index + 1, r, count);
// //   }
// // }

// void countNumberOfInversions(vector<int> &A, int p, int r, int &count)
// {
//   if (p < r)
//   {
//     int index = myPartition(A, p, r, count);
//     countNumberOfInversions(A, p, index - 1, count);
//     countNumberOfInversions(A, index + 1, r, count);
//   }
// }

// マージソートで数えるぞ！
void merge(vector<long long> &A, int start, int middle, int end, long long &count)
{
  int leftSize = middle - start + 1;
  int rightSize = end - middle + 1;
  vector<long long> left(middle - start + 1);
  vector<long long> right(end - middle + 1);

  for (int i = 0; i < middle - start; i++) {
    left[i] = A[start + i];
  }
  for (int i = 0; i < end - middle; i++) {
    right[i] = A[middle + i];
  }
  left[leftSize - 1] = LLONG_MAX;
  right[rightSize - 1] = LLONG_MAX;

  // cout << "=========" << endl;
  int i = 0;
  int j = 0;
  for (int k = start; k < end; k++) {
    if (left[i] <= right[j]) {
      A[k] = left[i];
      i++;
    }
    else
    {
      A[k] = right[j];
      // printVector(left);
      // printVector(right);
      // printVector(A);
      // cout << "middle; " << middle -start << endl;
      // cout << "i: " << i << endl;
      // cout << "middle - i: " << middle - start - i << endl;

      count += middle - start - i;
      j++;
    }
  }
}

void countNumberOfInversionsByMerge(vector<long long> &A, int start, int end, long long &count) {
  if (end - start > 1)
  {
    int middle = (start + end) / 2;

    countNumberOfInversionsByMerge(A, start, middle, count);
    countNumberOfInversionsByMerge(A, middle, end, count);
    merge(A, start, middle, end, count);
  }
}

    // void countNumberOfInversions(vector<int> A, int p, int r, int &count)
    // {
    //   if (p < r) {
    //     resultValue result = myPartition(A, p, r, count);
    //     countNumberOfInversions(result.list, p, result.index - 1, count);
    //     countNumberOfInversions(result.list, result.index + 1, r, count);
    //   }
    // }

//     void countNumberOfInversions(vector<int> &A, int p, int r, int &count)
// {
//   if (p < r)
//   {
//     int index = myPartition(A, p, r, count);
//     countNumberOfInversions(A, p, index - 1, count);
//     countNumberOfInversions(A, index + 1, r, count);
//   }
// }

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<long long> A(n);
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }


  long long count = 0;
  countNumberOfInversionsByMerge(A, 0, A.size(), count);
  // printVector(A);
  cout << count << endl;

  return 0;
}
