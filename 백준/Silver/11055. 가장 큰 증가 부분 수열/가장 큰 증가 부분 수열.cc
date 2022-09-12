#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1001], sum[1001];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                sum[i] = max(sum[i], sum[j]);
        sum[i] += arr[i];
    }
    cout << *max_element(sum, sum + n);
    return (0);
}