// https://www.acmicpc.net/problem/2798 (블랙잭)
#include <bits/stdc++.h>
using namespace std;

int card[101];
int mx, sum, n, m;

void    solution(int idx, int cnt)
{
    if (cnt == 3)
    {
        if (sum <= m && sum > mx)
            mx = sum;
        return ;
    }

    for (int i = idx + 1; i < n; i++)
    {
        sum += card[i];
        solution(i, cnt + 1);
        sum -= card[i];
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> card[i];

    solution(-1, 0);
    cout << mx;
    return (0);
}