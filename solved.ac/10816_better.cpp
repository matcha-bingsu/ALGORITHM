// https://www.acmicpc.net/problem/10816 (숫자카드2)
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> m;
int                     num;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n1, n2;
    cin >> n1;
    while (n1--)
    {
        cin >> num;
        if (m.find(num) != m.end())
            m[num] += 1;
        else
            m[num] =  1;
    }
    cin >> n2;
    while (n2--)
    {
        cin >> num;
        if (m.find(num) == m.end())
            cout << "0 ";
        else
            cout << m[num] << ' ';
    }
    return (0);
}