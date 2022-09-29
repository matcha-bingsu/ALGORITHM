#include <bits/stdc++.h>
using namespace std;
int l, c;

void    recur(char *arr, char *ans, int idx, int from)
{
    if (idx == l)
    {
        int j = 0;
        int m = 0;
        for (int i = 0; i < l; i++)
        {
            if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
                m++;
            else
                j++;
        }
        if (m >= 1 && j >= 2)
        {
            for (int i = 0; i < l; i++)
                cout << ans[i];
            cout << '\n';
        }
        return ;
    }
    for (int i = from; i <= c - l + idx; i++)
    {
        ans[idx] = arr[i];
        recur(arr, ans, idx + 1, i + 1);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> l >> c;
    char arr[c];
    char ans[l];
    for (int i = 0; i < c; i++)
        cin >> arr[i];
    sort(arr, arr + c);
    recur(arr, ans, 0, 0);
    return (0);
}