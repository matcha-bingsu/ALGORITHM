//https://www.acmicpc.net/problem/1406 [에디터]

#include <bits/stdc++.h>
using namespace std;

int  main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  list<char>  L;
  string      arr;
  int         t;
  char        order;
  list<char>::iterator  it;

  cin >> arr;
  for(char e : arr)
    L.push_back(e);

  it = L.end();
  cin >> t;  
  for(int i = 0; i < t; i++)
  {
    cin >> order;
    if (it != L.begin() && order == 'L')
      it--; 
    else if (it != L.end() && order == 'D')
      it++;
    else if (it != L.begin() && order == 'B')
    {
      it--;
      it = L.erase(it);
    }
    else if (order == 'P')
    {
      cin >> order;
      L.insert(it, order);
    }
  }
  for (auto e : L)
    cout << e;
}