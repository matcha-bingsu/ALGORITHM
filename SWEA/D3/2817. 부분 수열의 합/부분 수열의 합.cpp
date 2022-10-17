#include <bits/stdc++.h>
using namespace std;
int n, k, cnt;

void    backtracking(int *arr, int total, int idx)
{
    if (total >= k)
    {
        if (total == k)
            cnt++;
        return ;
    }
    for (int i = idx; i < n; i++)
    {
        total += arr[i];
        backtracking(arr, total, i + 1);
        total -= arr[i];
    }

}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;
    cin >> test_case;

    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        cnt = 0;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        backtracking(arr, 0, 0);
        cout << '#' << cur_case << ' ' << cnt << '\n';
    }
    return (0);
}