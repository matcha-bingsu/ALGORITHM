//https://www.acmicpc.net/problem/1475 [방 번호]

#include <bits/stdc++.h>
using namespace std;

int card[10];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;

    cin >> num;
    while (num > 0)
    {
      if (num % 10 == 6 || num % 10 == 9)
      {
        if (card[6] > card[9])
          card[9]++;
        else if (card[6] < card[9])
          card[6]++;
        else
          card[num % 10]++;
      }
      else
        card[num % 10]++;
      num /= 10;
    }
    cout <<  *max_element(card, card + 10);
}