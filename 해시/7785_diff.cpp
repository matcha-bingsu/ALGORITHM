// https://www.acmicpc.net/problem/7785 (회사에 있는 사람)
#include <bits/stdc++.h>
using namespace std;
vector<pair<string, string> >   v;
string  merged[1000002];
string  status[1000002];
string  answer[1000002];
int     idx;
string  tmp;

void    merge(int st, int ed)
{
    int mid = (st + ed) / 2;
    int p1 = st;
    int p2 = mid;
    for (int i = st; i < ed; i++)
    {
        if (p1 == mid)
        {
            merged[i] = v[p2].first;
            status[i] = v[p2++].second;
        }
        else if (p2 == ed)
        {
            merged[i] = v[p1].first;
            status[i] = v[p1++].second;
        }
        else if (v[p1].first > v[p2].first)
        {
            merged[i] = v[p2].first;
            status[i] = v[p2++].second;
        }
        else
        {
            merged[i] = v[p1].first;
            status[i] = v[p1++].second;
        }
    }
    for (int i = st; i < ed; i++)
        v[i] = {merged[i], status[i]};
}

void    solution(int st, int ed)
{
    if (ed - st == 1)
        return ;
    int mid = (st + ed) / 2;
    solution(st, mid);
    solution(mid, ed);
    merge(st, ed);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string  name;
        string  exist;
        cin >> name >> exist;
        v.push_back({name, exist});
    }

    solution(0, v.size());
    for (int i = 0; i < n; i++)
    {
        if (merged[i] != tmp && status[i - 1] == "enter")
            answer[idx++] = merged[i - 1];
        tmp = merged[i];
    }

    sort(answer, answer + idx, greater<string>());
    for (int i = 0; i < idx; i++)
        cout << answer[i] << '\n';
    return (0);
}