// https://www.acmicpc.net/problem/7785 (회사에 있는 사람)
#include <bits/stdc++.h>
using namespace std;

int comp(string str1, string str2)
{
    return (str1 > str2);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    unordered_set<string>   s;
    int                     n;

    cin >> n;
    while (n--)
    {
        string name, exist;

        cin >> name >> exist;
        if (exist == "enter")
            s.insert(name);
        else
            s.erase(name);
    }
    vector<string>  ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), comp);
    for (auto c : ans)
        cout << c << '\n';
    return (0);
}