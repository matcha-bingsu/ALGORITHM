#include <bits/stdc++.h>
using namespace std;
int cnt, mx, mn;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string  a, b;
    cin >> a >> b;

    if (a.size() == b.size())
    {
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                cnt++;
    }
    else
    {
        for (int i = 0; i < b.size(); i++)
        {   
            int reset_y = i;
            int j = -1;
            int cnt2 = 0;
            cnt = 0;
            while (++j < a.size())
            {
                if (b[i] == '\0')
                    break;
                if (a[j] != b[i])
                    cnt++;
                if (a[j] == b[i])
                    cnt2++;
                i++;
            }
            if (cnt2 >= mx)
            {
                mx = cnt2;
                mn = cnt;
            }
            i = reset_y;
        }
        cnt = mn;
    }
    cout << cnt;
    return (0);
}