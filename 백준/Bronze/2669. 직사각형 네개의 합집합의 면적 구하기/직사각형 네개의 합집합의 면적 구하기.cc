#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int total = 0;
    int x1, x2, y1, y2;
    int board[101][101];

    fill(board[0], &board[100][101], 0);

    for (int i = 0; i < 4; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++)
            for (int j = x1; j < x2; j++)
                board[i][j] = 1;
    }

    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            total += board[i][j];
    cout << total;
    return (0);
}