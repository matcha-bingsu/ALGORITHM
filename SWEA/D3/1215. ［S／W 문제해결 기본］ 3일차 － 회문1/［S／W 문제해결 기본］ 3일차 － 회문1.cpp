#include <bits/stdc++.h>
using namespace std;
int len, cnt;

void    is_palindrome(int flag, string str[], int x, int y)
{
    int i = 0;

    if (flag)
    {
        while (i <= len / 2 && str[x][y + i] == str[x][y + len - i])
            i++;
        if (i > len / 2)
            cnt++;
    }
    else
    {
        while (i <= len / 2 && str[x + i][y] == str[x + len - i][y])
            i++;
        if (i > len / 2)
            cnt++;
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int cur_case = 1; cur_case <= 10; cur_case++)
    {
        cnt = 0;
        string arr[8];

        cin >> len;
        len--;
        for (int i = 0; i < 8; i++)
            cin >> arr[i];
        
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (i + len < 8)
                    is_palindrome(0, arr, i, j);
                if (j + len < 8)
                    is_palindrome(1, arr, i, j);
            }
        }
        cout << '#' << cur_case << ' ' << cnt << '\n';
    }
    return (0);
}
