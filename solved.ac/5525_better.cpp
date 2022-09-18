#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
string s;


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        if (s[i] == 'O')
            continue;
        int cnt = 0;
        while (s[i + 1] == 'O' && s[i + 2] == 'I')
        {
            cnt++;
            i += 2;
            if (cnt == n)
            {
                ans++;
                cnt--;
            }
        }
    }
    cout << ans;
    return (0);
}