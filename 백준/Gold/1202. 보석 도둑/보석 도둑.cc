#include <bits/stdc++.h>
using namespace std;

void    init(vector<pair<int, int>>  &jel, multiset<int> &bag)
{
    int jewellery, bags;
    int weight, price;

    cin >> jewellery >> bags;
    while (jewellery--)
    {
        cin >> weight >> price;
        jel.push_back({price, weight});
    }
    while (bags--)
    {
        cin >> weight;
        bag.insert(weight);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int j = -1;
    long long ans = 0;
    multiset<int> bag;
    vector<pair<int, int>>  jel;

    init(jel, bag);

    sort(jel.begin(), jel.end());

    for (int i = jel.size() - 1; i >= 0; i--)
    {
        auto it = bag.lower_bound(jel[i].second);
        if (it != bag.end())
        {
            ans += jel[i].first;
            bag.erase(it);
        }
    }
    cout << ans;
    return (0);
}