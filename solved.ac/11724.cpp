#include <bits/stdc++.h>
using namespace std;
int cnt, v, e;
int chck[1001];
int board[1001][1001];

void    rotate(int n)
{
    chck[n] = 1;
    for (int i = 1; i <= v; i++)
    {
        if (board[n][i] && !chck[i])
            rotate(i);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> v >> e;

    while (e--)
    {
        int num1, num2;
        cin >> num1 >> num2;
        board[num1][num2] = 1;
        board[num2][num1] = 1;
    }

    for (int i = 1; i <= v; i++)
    {
        if (!chck[i])
        {
            cnt++;
            rotate(i);
        }
    }
    cout << cnt;
    return (0);
}