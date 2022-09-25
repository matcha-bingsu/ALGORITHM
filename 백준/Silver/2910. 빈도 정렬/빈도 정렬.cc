#include <bits/stdc++.h>
using namespace std;
int n, number, m;
unordered_map<int, int> mp; 
unordered_map<int, int> mp2;
vector<pair<int, int> > v;     

bool    compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return (mp2[a.first] < mp2[b.first]);
    return (a.second > b.second);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        if (mp.find(number) == mp.end())
        {
           mp.insert({number, 1});
           mp2.insert({number, i});
        }
        else
           mp[number]++;
    }
    for (auto c : mp)
        v.push_back({c.first, c.second});
    sort(v.begin(), v.end(), compare);
    for (auto c : v)
        for (int i = 0; i < c.second; i++)
            cout << c.first << ' ';
    return (0);
}