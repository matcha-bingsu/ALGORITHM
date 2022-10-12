#include <bits/stdc++.h>
using namespace std;

int    calculate(int times, int *arr)
{
    times++;
    while (times--)
    {
        int smallest_idx, tallest_idx;
        int mx = 0;
        int mn = 101;

        for (int i = 0; i < 100; i++)
        {
            if (arr[i] < mn)
            {
                smallest_idx = i;
                mn = arr[i];
            }
            if (arr[i] > mx)
            {
                tallest_idx = i;
                mx = arr[i];
            }
        }
        if (times == 0)
            return (arr[tallest_idx] - arr[smallest_idx]);
        else
        {
            arr[smallest_idx]++;
            arr[tallest_idx]--;
        }
    }
    return (0);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int test_case = 1; test_case <= 10; test_case++)
    {
        int times;
        int arr[100];

        cin >> times;
        for (int i = 0; i < 100; i++)
            cin >> arr[i];
        cout << '#' << test_case << ' ' << calculate(times, arr) << '\n';
    }
    return (0);
}