//https://www.acmicpc.net/problem/10773 [제로]

#include <bits/stdc++.h>
using namespace std;

int  main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(0);

  stack<int>  dat;
  int         t, n, sum;

  cin >> t;
  while (t--)
  {
    cin >> n;
    if (!n)
      dat.pop();
    else
      dat.push(n);
  }
  sum = 0;
  while (!dat.empty())
  {
    sum += dat.top();
    dat.pop();
  }
  cout << sum;
}