#include <bits/stdc++.h>
using namespace std;
int board[11][11];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    board[0][1] = 1;
    int test_case, number;

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= i; j++)
            board[i][j] = board[i - 1][j - 1] + board[i - 1][j];
    }

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        cin >> number;
        cout << '#' << cur_case << '\n';
        for (int i = 1; i <= number; i++)
        {
            for (int j = 1; j <= i; j++)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
    }
    return (0);
}