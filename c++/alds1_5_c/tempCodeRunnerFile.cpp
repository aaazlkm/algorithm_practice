#include <bits/stdc++.h>
#include <iostream>
using namespace std;
static const double pi = 3.141592653589793;

struct Position
{
  double x;
  double y;
};

void printPosition(Position position)
{
  printf("%.8f %.8f\n", position.x, position.y);
}

vector<Position> divideIntoThreeEqualParts(Position start, Position end){
  struct Position position1;
  position1.x = start.x + (end.x - start.x) / 3;
  position1.y = start.y + (end.y - start.y) / 3;
  struct Position position2;
  position2.x = start.x + (end.x - start.x) * 2 / 3;
  position2.y = start.y + (end.y - start.y) * 2 / 3;
  return vector {position1, position2};
}

Position calculateTriableTopPosition(Position start, Position end){
  struct Position position;
  double vectorStartToEndX = (end.x - start.x);
  double vectorStartToEndY = (end.y - start.y);
  position.x = start.x + vectorStartToEndX * cos(pi / 3) - vectorStartToEndY * sin(pi / 3);
  position.y = start.y + vectorStartToEndX * sin(pi / 3) + vectorStartToEndY * cos(pi / 3);
  return position;
}

void drawKoch(int i, int n, Position start, Position end)
{
  if (i == n)
  {
    printPosition(start);
    return;
  }

  vector<Position> positions = divideIntoThreeEqualParts(start, end);
  Position newStartPosition = positions[0];
  Position newEndPosition = positions[1];
  Position triableTopPosition = calculateTriableTopPosition(newStartPosition, newEndPosition);


  drawKoch(i + 1, n, start, newStartPosition);
  drawKoch(i + 1, n, newStartPosition, triableTopPosition);
  drawKoch(i + 1, n, triableTopPosition, newEndPosition);
  drawKoch(i + 1, n, newEndPosition, end);
}

int main()
{
  std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  struct Position position1;
  position1.x = 0;
  position1.y = 0;
  struct Position position2;
  position2.x = 100;
  position2.y = 0;
  drawKoch(0, n,position1, position2);
  printPosition(position2);

  return 0;
}
