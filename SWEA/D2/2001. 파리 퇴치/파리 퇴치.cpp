#include <bits/stdc++.h>
using namespace std;
int mx;

void    get_max(int (*board)[15], int x, int y, int m)
{
    int tmp = 0;

    for (int i = x; i < x + m; i++)
    {
        for (int j = y; j < y + m; j++)
            tmp += board[i][j];
    }
    mx = max(mx, tmp);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case, n, m;
    int board[15][15];

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        mx = 0;
        fill(&board[0][0], &board[14][15], 0);
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i + m - 1 < n && j + m - 1 < n)
                    get_max(board, i, j, m);
            }
        }
        cout << '#' << cur_case << ' ' << mx << '\n';
    }
    return (0);
}