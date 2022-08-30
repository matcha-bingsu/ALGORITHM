//https://www.acmicpc.net/problem/2579 (계단 오르기)
#include <bits/stdc++.h>
using namespace std;

int save[301][3];
int stair[301];
int n;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> stair[i];
    
    save[1][1] = stair[1];
    save[1][2] = 0;
    if (n != 1)
    {
        save[2][1] = stair[2];
        save[2][2] = stair[1] + stair[2];
    }

    for (int i = 3; i <= n; i++)
    {
        save[i][1] = max(save[i - 2][1], save[i - 2][2]) + stair[i];
        save[i][2] = save[i - 1][1] + stair[i];
    }

    cout << max(save[n][1], save[n][2]);
    return (0);
}
