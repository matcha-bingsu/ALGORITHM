#include <bits/stdc++.h>
using namespace std;
string  s;
int     len;
int arr[51];

int recur(int n)
{
    int cnt = 0;
    for (int i = n; i < len; i++)
    {
        if (s[i] == '(' && !arr[i])
        {
            cnt--;
            arr[i] = 1;
            cnt += atoi(&s[i - 1]) * recur(i + 1);
        }
        else if (s[i] == ')' && !arr[i])
        {
            arr[i] = 1;
            return (cnt);
        }
        else if (!arr[i])
        {
            cnt++;
            arr[i] = 1;
        }
    }
    return (cnt);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> s;
    len = s.length();

    cout << recur(0);
    return (0);
}