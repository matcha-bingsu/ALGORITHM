#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[16][16];

int chck (int num)
{
    if (num == k)
        return (1);
    else
        return (0);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        int ans = 0;

        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }

        for (int i = 0; i < n; i++)
        {
            int tmp = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                {
                    if (arr[i][j])
                        tmp++;
                    else
                        continue;
                }
                else if (arr[i][j - 1] && arr[i][j])
                    tmp++;
                else if (!arr[i][j - 1] && arr[i][j])
                {
                    ans += chck(tmp);
                    tmp = 1;
                }
            }
            ans += chck(tmp);
        }
        
        for (int j = 0; j < n; j++)
        {
            int tmp = 0;
            for (int i = 0; i < n; i++)
            {
                if (i == 0)
                {
                    if (arr[i][j])
                        tmp++;
                    else
                        continue;
                }
                else if (arr[i - 1][j] && arr[i][j])
                    tmp++;
                else if (!arr[i - 1][j] && arr[i][j])
                {
                    ans += chck(tmp);
                    tmp = 1;
                }
            }
            ans += chck(tmp);
        }
        cout << '#' << cur_case << ' ' << ans << '\n'; 
    }
    return (0);
}