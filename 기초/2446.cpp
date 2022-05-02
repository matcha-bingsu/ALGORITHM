//https://www.acmicpc.net/problem/2446[별 찍기 - 9]

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int  N;
  
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < i; j ++)  cout << ' ';
    for(int q = 0; q < 2 * (N - i) - 1; q++)  cout << '*';
    cout << '\n';
  }
  
  for(int i = 2; i <= N; i++)
  {
    for(int j = 0; j < N - i; j++)  cout << ' ';
    for(int q = 0; q < 2 * i - 1; q++)  cout << '*';
    cout << '\n';
  }
}