// https://www.acmicpc.net/problem/10814 
#include <bits/stdc++.h>
using namespace std;

bool    compare(pair<int, string> a, pair<int, string> b)
{
    return (a.first < b.first);
}

int main(void)
{
    int num;
    cin >> num;
    pair<int, string>   tmp;
    vector<pair<int, string> >  arr;

    for (int i = 0; i < num; i++)
    {
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }

    stable_sort(arr.begin(), arr.end(), compare); // 보낸 값이 동일하면 stable_sort의 원리에 따라 그냥 존재하게 된다.
    for (auto c : arr)
        cout << c.first << ' ' << c.second << '\n';
}