//https://www.acmicpc.net/problem/2577 [숫자의 개수]

#include <bits/stdc++.h>
using namespace std;

int  board[10];
int  main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int  a, b, c, mul;

  cin >> a >> b >> c;
  mul = a * b * c;
  while (mul > 0)
  {
    board[mul % 10] += 1;
    mul /= 10;
  }
  for (int e : board)
    cout << e << '\n';
}