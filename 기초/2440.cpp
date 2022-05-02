//https://www.acmicpc.net/problem/2440[별 찍기 - 3]

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int  N;

  cin >> N;
  for(int i = N; i >= 1; i--)
  {
    for(int j = 1; j <= N; j++)
      if (j <= i)
        cout << '*';
    cout << "\n";
  }
}