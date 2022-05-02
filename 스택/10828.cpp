//https://www.acmicpc.net/problem/10828 [스택]

#include <bits/stdc++.h>
using namespace std;

int  main(void)
{
  stack<int> s;
  int        num, num2;
  string     order;

  cin >> num;
  while (num--)
  {
    cin >> order;
    if (order == "push")
    {
      cin >> num2;
      s.push(num2);
    }
    else if (order == "pop" || order == "top")
    {
      if (!s.empty())
      {
        cout << s.top() << '\n';
        if (order == "pop")
          s.pop();
      }
      else
        cout << -1 << '\n';
    }
    else if (order == "size")
      cout << s.size() << '\n';
    else
      cout << s.empty() << '\n';
  }
}