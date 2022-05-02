//https://www.acmicpc.net/problem/2493 [탑]

#include <bits/stdc++.h>
#include <utility>
using namespace std;

//이전에 큰애들만 사라남는다. 자리는 딴 곳에 저장할테니

int  main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(0);

  stack<pair<int, int>> dat;
  int                   t, n;

  dat.push({100000001, 0});
  cin >> t;
  for(int i = 1; i <= t; i++)
  {
    cin >> n;
    while (dat.top().first < n)
      dat.pop();
    
    cout << dat.top().second << ' ';
    dat.push({n, i});
  }
}