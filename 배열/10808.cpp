//https://www.acmicpc.net/problem/10808[알파벳 개수]

#include <bits/stdc++.h>
using namespace std;

int  main(void)
{
  
  //char  word[100];
  int  times[26];
  string  ss;
  
  fill(times, times + 26, 0);
  //0 <= <26
  //cin >> word;
  cin >> ss;
  for(int w : ss)
      times[w - 97] += 1;
  
  for(int i = 0; i < 26; i++)
    cout << times[i] << ' ';
}
