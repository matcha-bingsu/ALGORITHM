//https://www.acmicpc.net/problem/2442[별 찍기 - 5]

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int  N, NN;

  cin >> N;
  NN = 2 * N;
  for(int i = 0; i < N; i++)
  {
    for(int j = 1; j <= N + i; j++)
      if (j <= N + i && j >= N - i)
        cout << '*';
      else
        cout << ' ';
    cout << "\n";
  }
}