#include <bits/stdc++.h>
using namespace std;

int    gaesan(int (*board)[100], int* x, int* y, int *cross)
{
    int mx = -2147483648;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            x[i] += board[i][j];
            y[j] += board[i][j];
            if (i == j)
                cross += board[i][j];
        }
    }
    
    for (int i = 0; i < 100; i++)
    {
        mx = max(mx, x[i]);
        mx = max(mx, y[i]);
    }
    return (mx);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int times = 10;
    while (times--)
    {
        int cur_test, largest;
        int cross = 0;
        int x[100], y[100];
        int board[100][100];

        cin >> cur_test;
        fill(x, x + 100, 0);
        fill(y, y + 100, 0);
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                cin >> board[i][j];

        largest = max(gaesan(board, x, y, &cross), cross);
        cout << '#' << cur_test << ' ' << largest << '\n'; 
    }
    return (0);
}