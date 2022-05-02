//https://www.acmicpc.net/problem/2562[최댓값]

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int  num, max, index;

  max = 0;
  for(int i = 1; i < 10; i ++)
  {
    cin >> num;
    if (num > max)
    {
      max = num;
      index = i;
    }
  }
  cout << max << '\n' << index;
}