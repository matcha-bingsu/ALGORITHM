// https://www.acmicpc.net/problem/2606
#include <bits/stdc++.h>
using namespace std;
int cnt;
int visited[101];
vector<int> vec[101];

void    round(int n)
{
    cnt++;
    visited[n] = 1;

    for (int i = 0; i < vec[n].size(); i++)
    {
        if (!visited[vec[n][i]])
            round(vec[n][i]);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int v, e;
    cin >> v >> e;

    vec->resize(v + 1);

    while (e--)
    {
        int num1, num2;
        cin >> num1 >> num2;
        vec[num1].push_back(num2);
        vec[num2].push_back(num1);
    }

    round(1);
    cout << cnt - 1;
    return (0);
}
