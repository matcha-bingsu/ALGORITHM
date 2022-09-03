// https://www.acmicpc.net/problem/1477 (휴게소 세우기)
#include <bits/stdc++.h>
using namespace std;
int arr[1005];
int mx;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    arr[n] = l;

    while (m--)
    {
        int cur = 0;
        int st, ed;
        sort(arr, arr + (n + 1));
        for (int i = 0; i <= n ; i++)
        {
            if (arr[i] - cur > mx)
            {
                mx = arr[i] - cur;
                st = cur;
                ed = arr[i];
            }
            cur = arr[i];
        }
        arr[++n] = st + ((ed - st) / 2);
    }

    cout << mx;
    return (0);
}
