#include <bits/stdc++.h>
using namespace std;
int         n;
vector<long long> v;

long long    ft_atoi(const char *str)
{
    long long ans = 0;
    while (*str)
    {
        ans = ans * 10 + (*str - '0');
        str++;
    }
    return (ans);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    while (n--)
    {
        string  s;
        string  tmp = "";
        cin >> s;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            string tmp2 = "";
            tmp2 = s[i];
            tmp.append(tmp2);
        }
        v.push_back(ft_atoi(tmp.c_str()));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
    return (0);
}