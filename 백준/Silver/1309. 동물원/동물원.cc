#include <bits/stdc++.h>
using namespace std;

void    solve(int n)
{
    int cage[n + 1][3];

    cage[1][0] = 1;
    cage[1][1] = 1;
    cage[1][2] = 1;

    for (int i = 2; i <= n; i++)
    {
        cage[i][0] = (cage[i - 1][1] + cage[i - 1][2]) % 9901;
        cage[i][1] = (cage[i - 1][0] + cage[i - 1][2]) % 9901;
        cage[i][2] = (cage[i - 1][0] + cage[i - 1][1] + cage[i - 1][2]) % 9901;
    }
    cout << (cage[n][0] + cage[n][1] + cage[n][2]) % 9901;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    solve(n);
    return (0);
}