//https://www.acmicpc.net/problem/1158 [요세푸스 문제]

#include <bits/stdc++.h>
using namespace std;

int  main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int  N, K, count, index;
  int  num[50001] = {0, };
  
  index = 1;
  cin >> N >> K;

  cout <<  '<';
  for (int i = 0; i < N; i++)
  {
    count = 0;
    while (count < K)
    {
      if (index > N)
        index = 1;
      if (num[index] == 0)
        count++;
      if (index == N)
      {
        if (count != K)
          index = 0;
      }
      index++;
    }
    num[index - 1] = 1;
    cout << index - 1;
    if (i != N - 1)
      cout << ", ";
  }
  cout << '>';
}