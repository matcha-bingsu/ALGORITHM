#include <bits/stdc++.h>
using namespace std;
int tc;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> tc;
    while (tc--)
    {
        int arr[10];
        for (int i = 0; i < 10; i++)
            cin >> arr[i];
        sort(arr, arr + 10, greater());
        cout << arr[2] << '\n';
    }
    return (0);
}