#include <bits/stdc++.h>
using namespace std;
int max_len;
string  arr[100];

void    is_palindrome(int flag, int len, int x, int y)
{     
    int i = 0;

    if (!flag)
    {
        for (i = 0; i < len / 2; i++)
        {
            if (arr[x + i][y] != arr[x + len - 1 - i][y])
                break;
        }
        if (i == len / 2)
            max_len = max(max_len, len);
    }
    else
    {
        for (i = 0; i < len / 2; i++)
        {
            if (arr[x][y + i] != arr[x][y + len - 1 - i])
                break;
        }
        if (i == len / 2)
            max_len = max(max_len, len);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case = 10;
    int cur_case;

    while (test_case--)
    {
        max_len = 1;

        cin >> cur_case;
        for (int i = 0; i < 100; i++)
            cin >> arr[i];
        
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                for (int len = max_len; len <= 100; len++)
                {
                    if (i + len - 1< 100)
                        is_palindrome(0, len, i, j);
                    if (j + len - 1 < 100)
                        is_palindrome(1, len, i, j);
                }
            }
        }
        cout << '#' << cur_case << ' ' << max_len << '\n';
    }
    return (0);
}