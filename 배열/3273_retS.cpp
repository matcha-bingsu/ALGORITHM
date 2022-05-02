//https://www.acmicpc.net/problem/3273 [두 수의 합]

#include <bits/stdc++.h>
using namespace std;

bool  card[2000001];
int  order[100001];
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int  n, x, ans;
  ans = 0;
  cin >> n;
  //들어오는 숫자 0부터 저장
  for(int i = 0; i < n; i++) cin >> order[i];
  cin >> x;

  for(int i = 0; i < n; i++)
  {
    if (x - order[i] > 0 && card[x - order[i]])
      ans++;
    card[order[i]] = true;
  }
  cout << ans;
}