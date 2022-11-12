#include <bits/stdc++.h>
using namespace std;

int calculate(int flag, int target, int n)
{

    int cnt = 2;
    int pre2 = n;
    vector<int> v;
    int pre1 = target;
    int cur = pre1 - pre2;

    v.push_back(pre1);
    v.push_back(pre2);
    while (cur >= 0)
    {
        v.push_back(cur);
        pre1 = pre2;
        pre2 = cur;
        cur = pre1 - pre2;
        cnt++;
    }
    if (!flag)
        return (cnt);
    else
    {
        cout << cnt << '\n';
        for (auto c : v)
            cout << c  << ' ';
        return (0);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int target, ans;
    int mx = 0;

    cin >> target;
    for (int n = target; n >= 1; n--)
    {
        int cnt = calculate(0, target, n);
        if (cnt > mx)
        {
            mx = cnt;
            ans = n;
        }
    }
    calculate(1, target, ans);
    return (0);
}