//https://www.acmicpc.net/problem/10093[숫자]

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long  A, B;
  long long  tmp;

  cin >> A >> B;
  if (A > B)
  {
    tmp = A;
    A = B;
    B = tmp;
  }
  else if (A == B)
  {
    cout << 0 << "\n";
    return (0);
  }
  cout << B - A - 1 << "\n";
  while (++A < B)
    cout << A << " ";
}