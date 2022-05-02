//https://www.acmicpc.net/problem/5397 [키로커]

#include <bits/stdc++.h>
using namespace std;

int  main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int  n;
  cin >> n;

  while (n--)
  {
    list<char>  L = {};
    string      s;
    auto        p = L.begin();

    cin >> s;
    for (auto c : s)
    {
      if (c == '<'){
        if (p != L.begin()) p--;
      }
      else if (c == '>'){
        if (p != L.end())  p++;
      }
      else if (c == '-'){
        if (p != L.begin()){
          p--;
          p = L.erase(p);
        }
      }
      else
        L.insert(p, c);
    }
    for(auto c : L)
      cout << c;
    cout << '\n';
  }
}