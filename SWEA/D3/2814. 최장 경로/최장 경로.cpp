#include <bits/stdc++.h>
using namespace std;
int mx, N, M;
bool chck[11];
int arr[11][11];

void    init()
{
    mx = 0;
    fill(chck, chck + 11, 0);
    fill(arr[0], &arr[11][11], 0);

    cin >> N >> M;
    while (M--)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
}

void    dfs(int num, int len)
{
    for (int i = 1; i <= N; i++)
    {
        if (!chck[i] && arr[num][i])
        {
            chck[i] = true;
            dfs(i, len + 1);
            chck[i] = false;
        }
    }
    mx = max(mx, len);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        init();

        for (int i = 1; i <= N; i++)
        {
            chck[i] = true;
            dfs(i, 1);
            chck[i] = false;
        }
        cout << '#' << cur_case << ' ' << mx << '\n';
    }
    return (0);
}