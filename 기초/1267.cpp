//https://www.acmicpc.net/problem/1267[핸드폰 요금]

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int  Y, M, loop, n;

  Y = 0;
  M = 0;
  cin >> loop;
  for(int i = 0; i < loop; i++)
  {
    cin >> n;
    Y += ((n / 30) + 1) * 10;
    M += ((n / 60) + 1) * 15;
  }
  if (Y < M)
    cout << "Y " << Y;
  else if (Y > M)
    cout << "M " << M;
  else
    cout << "Y M " << Y;
}
