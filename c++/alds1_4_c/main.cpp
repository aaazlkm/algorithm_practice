#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct input
{
  string operation;
  string value;
};

static const int tableSize = 1042567;
class HashTable
{

public:
  explicit HashTable() : table(tableSize) {}

  vector<string> table;

  void insert(string data)
  {
    int key = convertDataToKey(data);
    for (int i = 0; i < tableSize; i++)
    {
      int index = hashKey(key, i);
      if (table[index] == "")
      {
        table[index] = data;
        break;
      }
      else if (table[index] == data)
      {
        break;
      }
    }
  }

  bool search(string data)
  {
    int key = convertDataToKey(data);
    for (int i = 0; i < tableSize; i++)
    {
      int index = hashKey(key, i);
      if (table[index] == "")
      {
        return false;
      }
      else if (table[index] == data)
      {
        return true;
      }
    }
    return false;
  }

private:
  int hashKey(int key, int i)
  {
    return (hashKey1(key) + i * hashKey2(key)) % tableSize;
  }

  int hashKey1(int key)
  {
    return key % tableSize;
  }

  int hashKey2(int key)
  {
    return key % (tableSize - 1);
  }

  int convertDataToKey(string data)
  {
    int key = 0;
    for (int i = 0; i < data.length(); i++)
    {
      key += convertCharactorToKey(data.at(i)) * pow(5, (i + 1));
    }
    return key;
  }

  int convertCharactorToKey(char charactor)
  {
    if (charactor == 'A')
    {
      return 1;
    }
    else if (charactor == 'C')
    {
      return 2;
    }
    else if (charactor == 'G')
    {
      return 3;
    }
    else if (charactor == 'T')
    {
      return 4;
    }
    throw "Invalid character";
  }
};

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  input inputs[n];
  HashTable hashTable = HashTable();

  for (int i = 0; i < n; i++)
  {
    string operation, value;
    cin >> operation >> value;
    struct input input;
    input.operation = operation;
    input.value = value;
    inputs[i] = input;
  }

  for (int i = 0; i < n; i++)
  {
    input input = inputs[i];
    string operation = input.operation;
    string value = input.value;
    if (operation == "insert")
    {
      hashTable.insert(value);
    }
    else if (operation == "find")
    {
      if (hashTable.search(value))
      {
        cout << "yes" << endl;
      }
      else
      {
        cout << "no" << endl;
      }
    }
  }

  return 0;
}
