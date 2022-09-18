// https://www.acmicpc.net/problem/11866 (요세푸스 문제 0)
#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        v.push_back(i);

    cout << '<';
    while (!v.empty())
    {
        for (int i = 0; i < k - 1; i++)
        {
            v.push_back(v.front());
            v.erase(v.begin());
        }
        cout << *v.begin();
        if (v.size() != 1)
            cout << ", ";
        v.erase(v.begin());
    }
    cout << '>';
    return (0);
}