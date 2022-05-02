//https://www.acmicpc.net/problem/1874 [스택 수열]

#include <bits/stdc++.h>
using namespace std;

int  main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(0);

  int           t, n, i;
  stack<int>    num;
  vector<char>  ans;

  cin >> t;
  i = 1;
  while (t--)
  {
    cin >> n;
    while (i <= n)
    {
      num.push(i++);
      ans.push_back('+');
    }
    if (num.top() == n)
    {
      num.pop();
      ans.push_back('-');
    }
    else
    {
      cout << "NO\n";
      return (0);
    }
  }
  for (auto e : ans)
    cout << e << '\n';
}