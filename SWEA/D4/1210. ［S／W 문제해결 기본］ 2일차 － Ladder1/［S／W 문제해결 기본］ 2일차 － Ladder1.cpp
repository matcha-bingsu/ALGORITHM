#include <bits/stdc++.h>
using namespace std;

int calculate(int i, int j, int (*arr)[100])
{
    int forbidden_dir = 0;

    while (i != 0)
    {
        if (forbidden_dir != 1 && j > 0 && arr[i][j - 1] == 1)
        {
            j -= 1;
            forbidden_dir = 2;
        }
        else if (forbidden_dir != 2 && j < 99 && arr[i][j + 1] == 1)
        {
            j += 1;
            forbidden_dir = 1;
        }
        else if (arr[i - 1][j] == 1)
        {
            i -= 1;
            forbidden_dir = 0;
        }
    }
    return (j);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 10; i++)
    {
        int cur_case, ans;
        int arr[100][100];
        pair<int, int>  jackpot;

        cin >> cur_case;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 2)
                    jackpot = {i, j};
            }
        }
        ans = calculate(jackpot.first, jackpot.second, arr);
        cout << '#' << cur_case << ' ' << ans << '\n'; 
    }
    return (0);
}