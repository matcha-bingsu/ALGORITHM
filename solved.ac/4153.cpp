// https://www.acmicpc.net/problem/4153
#include <bits/stdc++.h>
using namespace std;
int arr[4];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (1)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        if (!arr[0] && !arr[1] && !arr[2])
            break;
        if ((arr[0] * arr[0]) + (arr[1] * arr[1]) == (arr[2] * arr[2]))
            cout << "right\n";
        else
            cout << "wrong\n";
    }
    return (0);
}
