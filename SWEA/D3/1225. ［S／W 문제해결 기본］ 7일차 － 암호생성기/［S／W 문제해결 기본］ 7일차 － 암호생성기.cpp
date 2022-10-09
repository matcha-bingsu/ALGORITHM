#include <bits/stdc++.h>
using namespace std;
#define MAX 2147483647

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int cur_test;
    int flag = 1;
    while (flag)
    {
        int arr[8];
        int mn = MAX;

        cin >> cur_test;
        if (cur_test == 10)
            flag = 0;
        for (int i = 0; i < 8; i++)
            cin >> arr[i];
        
        for (int i = 0; i < 8; i++)
        {
            int share = arr[i] % 15;
            if (share == 0)
            {
                mn = arr[i] / 15 - 1;
                break;
            }
            else
                mn = min(mn, arr[i] / 15);
        }
        for (int i = 0; i < 8; i++)
            arr[i] -= 15 * mn;
        
        int i = 0;
        int m = 1;
        while (arr[i] - m > 0)
        {
            arr[i] -= m;
            if (m == 5)
                m = 0;
            if (i == 7)
                i = -1;
            i++;
            m++;
        }

        cout << '#' << cur_test << ' ';
        for (int idx = i + 1; idx < 8; idx++)
            cout << arr[idx] << ' ';
        for (int idx = 0; idx < i; idx++)
            cout << arr[idx] << ' ';
        cout << 0 << '\n';
    }
    return (0);
}