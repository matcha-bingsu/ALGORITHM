// https://www.acmicpc.net/problem/12852 (1로 만들기 2)
#include <bits/stdc++.h>
using namespace std;
int arr[1000002];
int ptr[1000002];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {   
        int init;
        arr[i] = arr[i - 1] + 1;
        init = arr[i];
        ptr[i] = i - 1;

        if (i % 3 == 0)
        {
            arr[i] = min(arr[i], arr[i / 3] + 1);
            if (arr[i] != init)
                ptr[i] = i / 3;
        }
        if (i % 2 == 0)
        {
            arr[i] = min(arr[i], arr[i / 2] + 1);
            if (arr[i] != init)
                ptr[i] = i / 2;
        }
    }

    cout << arr[n] << '\n';
    int cur = n;
    while (true)
    {
        cout << cur << ' ';
        if (cur == 1)
            break;
        cur = ptr[cur];
    }
    return (0);
}