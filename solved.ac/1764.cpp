#include <bits/stdc++.h>
using namespace std;
int     i;
string  li[500001];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    unordered_set<string>   s;
    int                     n, m;
    string                  name;

    cin >> n >> m;
    while (n--)
    {
        cin >> name;
        s.insert(name);
    } 
    while (m--)
    {
        cin >> name;
        if (s.find(name) != s.end())
            li[i++] = name;
    }
    sort(li, li + i);
    cout << i << '\n';
    for (int j = 0; j < i; j++)
        cout << li[j] << '\n';
    return (0);
}