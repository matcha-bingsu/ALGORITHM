#include <bits/stdc++.h>
using namespace std;
int arr[9][9];

void    init(int *ans)
{
    ans = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cin >> arr[i][j];
    }
}

int number_chck(int *arr)
{
    for (int i = 1; i < 9; i++)
    {
        if (arr[i] != 1)
            return (0);
    }
    return (1);
}

int column_chck()
{
    int chck[10];

    for (int i = 0; i < 9; i++)
    {
        fill(chck, chck + 10, 0);
        for (int j = 0; j < 9; j++)
            chck[arr[i][j]]++;
        if (!number_chck(chck))
            return (0);
    }
    return (1);
}

int row_chck()
{
    int chck[10];

    for (int j = 0; j < 9; j++)
    {
        fill(chck, chck + 10, 0);
        for (int i = 0; i < 9; i++)
            chck[arr[i][j]]++;
        if (!number_chck(chck))
            return (0);
    }
    return (1);
}

int square_chck()
{
    int chck[10];

    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            fill(chck, chck + 10, 0);
            for (int si = i; si < i + 3; si++)
                for (int sj = j; sj < j + 3; sj++)
                    chck[arr[si][sj]]++;
            if (!number_chck(chck))
                return (0);
        }
    }
    return (1);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case, ans;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        init(&ans);

        ans = column_chck();

        if (ans)
            ans = row_chck();

        if (ans)
            ans = square_chck();
        
        cout << '#' << cur_case << ' ' << ans << '\n';
    }
    return (0);
}