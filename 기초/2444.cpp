//https://www.acmicpc.net/problem/2444[별 찍기 -7]

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int  N;
  
  cin >> N;
  for(int i = 1; i < 2 * N; i++)
  {
    if (i <= N)
    {
      for(int j = 0; j < N - i; j++)  cout << ' ';
      for(int q = 0; q < 2 * i - 1; q++)  cout << '*';
    }
    else
    {
      for(int j = 0; j < i - N; j++) cout << ' ';
      for(int q = 0; q <  2 * (2 * N - i) - 1; q++) cout << '*';
    }
    cout << '\n';
  }
}