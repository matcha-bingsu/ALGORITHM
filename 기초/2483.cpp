//https://www.acmicpc.net/problem/2438[별 찍기 - 1]

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int  N;

  cin >> N;
  for(int i = 1; i <= N; i++)
  {  
    for(int j = 1; j <= i; j++)
      cout << '*';
    cout << "\n";
  }
}
