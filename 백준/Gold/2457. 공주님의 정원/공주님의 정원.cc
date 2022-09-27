#include <bits/stdc++.h>
using namespace std;
int n, flag, mx;
vector<pair<int, int> >   v;
vector<int> ans;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    while (n--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({a * 100 + b, c * 100 + d});
    }
    sort(v.begin(), v.end());
    int standard = 301;
    for (int i = 0; i < v.size(); i++)
    {
        if (standard >= 1201)
        {
            flag++;
            break;
        }
        if (v[i].first <= standard)
        {
            mx = max(mx, v[i].second);
            if (mx >= 1201)
                goto here;
        }
        else if (v[i].first > mx)
            break;
        else
        {
            here:
            standard = mx;
            mx = 0;
            ans.push_back(1);
            i--;
        }
    }
    if (flag)
        cout << ans.size();
    else
        cout << 0;
    return (0);
}