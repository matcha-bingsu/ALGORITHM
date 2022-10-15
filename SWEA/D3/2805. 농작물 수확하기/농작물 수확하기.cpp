#include <bits/stdc++.h>
using namespace std;
int n;
int arr[50][50];

int calculate()
{
    int total = 0;

    for (int i = 0; i <= (n / 2); i++)
    {
        for (int j = i; j < n - i; j++)
        {
            total += arr[n / 2 - i][j];
            if (i != 0)
                total += arr[n / 2 + i][j];
        }
    }
    return (total);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        cin >> n;
        fill(arr[0], arr[50], 0);

        for (int i = 0; i < n; i++)
        {
            int j = 0;
            string  str;
            cin >> str;

            for (auto each : str)
                arr[i][j++] = each - '0';
        }
        cout << '#' << cur_case << ' ' << calculate() << '\n';
    }
}