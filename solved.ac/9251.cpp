#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string a, b;
    cin >> a >> b;

    for (int i = 1; i <= b.size(); i++)
        for (int j = 1; j <= a.size(); j++)
            if (b[i - 1] == a[j - 1])
                arr[i][j] = 1 + arr[i - 1][j - 1];
            else
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
    cout << arr[b.size()][a.size()];
    return (0);
}

