#include <bits/stdc++.h>
using namespace std;
int sum;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int arr[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        arr[i] = sum;
    }
    cout << accumulate(arr, arr + n, 0);
    return (0);
}