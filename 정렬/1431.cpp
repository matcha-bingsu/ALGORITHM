// https://www.acmicpc.net/problem/1431 (시리얼 번호)
#include <bits/stdc++.h>
using namespace std;
string  input[51];

int sum(string str)
{
    int n = 0;
    int idx = -1;

    while (str[++idx])
        if (str[idx] >= '0' && str[idx] <= '9')
            n += str[idx] - 48;
    return (n);
}

bool cmp(string str1, string str2)
{
    if (str1.length() != str2.length())
        return (str1.length() < str2.length());
    else if (sum(str1) - sum(str2) == 0)    
    {
        int i = 0;
        while (str1[i] && str2[i] && str1[i] == str2[i])
            i++;
        return (str1[i] < str2[i]);
    }
    else
        return (sum(str1) < sum(str2));
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input[i];
    sort(input, input + n, cmp);

    for (int i = 0; i < n; i++)
        cout << input[i] << '\n';
    return (0);
}