#include <bits/stdc++.h>
using namespace std;
int tmp, all, flag;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string  s;

    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
            tmp = tmp * 10 + (s[i] - '0');
        else if (s[i] == '-' || s[i] == '+')
        {
            if (flag)
                all -= tmp;
            else
                all += tmp;
            tmp = 0;
            if (s[i] == '-')
                flag++;
        }
    }
    if (flag)
        all -= tmp;
    else
        all += tmp;
    cout << all;
    return (0);
}