#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    int arr[10];
    int previous[10];

    cin >> n;

    arr[0] = 0;
    previous[0] = 0;
    fill(previous + 1, previous + 10, 1);
    fill(arr + 1, arr + 10, 1);

    while (--n)
    {
        fill(arr, arr + 10, 0);
        for (int i = 0; i < 10; i++)
        {
            if (i - 1 >= 0)
                arr[i - 1] += previous[i] % 1000000000;
            if (i + 1 <= 9)
                arr[i + 1] += previous[i] % 1000000000;
        }
        for (int i = 0; i < 10; i++)
            previous[i] = arr[i];
    }

    long long ans = 0;
    for (int i = 0; i < 10; i++)
        ans = (ans + arr[i]) % 1000000000;
    cout << ans;
    return (0);
}