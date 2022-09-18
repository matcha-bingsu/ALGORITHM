#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, num;
    cin >> n;
    while (n--)
    {
        int ans = 1;
        cin >> num;
        unordered_set<string>   item;
        unordered_map<string, int>  exact_item;

        while (num--)
        {
            string a, b;
            cin >> a >> b;
            item.insert(b);
            if (exact_item.find(b) == exact_item.end())
                exact_item.insert({b, 1});
            else
                exact_item[b] = exact_item[b] + 1;
        }
        for (auto c : item)
            ans *= exact_item[c] + 1;
        cout << ans - 1 << '\n';
    }
    return (0);
}