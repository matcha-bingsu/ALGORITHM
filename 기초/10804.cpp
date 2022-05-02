//https://www.acmicpc.net/problem/10804[카드 역배치]

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int  i, j, stan, tmp;
  int  card[20];

  for (int i = 0; i < 20; i++) card[i] = i + 1;
  
  for(int q = 0; q < 10; q++)
  {
    cin >> i >> j;
    stan = (i + j) / 2;
    while (i <= stan)
        swap(card[i++ - 1], card[j-- - 1]);
  }
  for(int i = 0; i < 20; i++) cout << card[i] << " ";
}