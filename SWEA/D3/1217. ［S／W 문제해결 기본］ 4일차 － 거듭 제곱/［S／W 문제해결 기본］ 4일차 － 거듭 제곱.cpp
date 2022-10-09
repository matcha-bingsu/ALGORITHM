#include <bits/stdc++.h>
using namespace std;

int recur(int n, int cur_times, int m)
{
    if (cur_times == m)
        return (n);
    return (n * recur(n, cur_times + 1, m));
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int flag = 1;
    while (flag)
    {
        int test_number, n, m;
        cin >> test_number >> n >> m;
        if (test_number == 10)
            flag = 0;
        cout << '#' << test_number << ' ' << recur(n, 1, m) << '\n';
    }
    return (0);
}