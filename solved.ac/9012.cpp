// https://www.acmicpc.net/problem/9012 (괄호)
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    
    while (n--)
    {
        stack<char> s;
        string      str;
        int         flag = 0;

        cin >> str;

        for (auto c : str)
        {
            if (c == '(')
                s.push('(');
            else
            {
                if (s.empty() || s.top() != '(')
                {
                    flag = 1;
                    break;
                }
                else
                    s.pop();
            }
        }
        if (flag || !s.empty())
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return (0);
}