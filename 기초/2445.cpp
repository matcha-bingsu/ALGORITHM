//https://www.acmicpc.net/problem/2445[별 찍기 - 8]

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int  N;
  
  cin >> N;
  for(int i = 1; i <= N; i++)
  {
    for(int j = 0; j < 2 * N; j++)
    {
      if (j < i || j > 2 * N - i - 1)
        cout << '*';
      else
        cout << ' ';
    }
    cout << '\n';
  }
  for(int i = 1; i < 2 * N - N; i++)
  {
    for(int j = 0; j < 2 * N; j++)
    {
      if (j < N + i && j > N - i - 1)
        cout << ' ';
      else
        cout << '*';
    }
    cout << '\n';
  }
}