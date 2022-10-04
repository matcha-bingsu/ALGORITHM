#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (next_permutation(arr, arr + n) == false)
        cout << -1;
    else
    {
        for (auto each : arr)
            cout << each << ' ';
    }

    return (0);
}
