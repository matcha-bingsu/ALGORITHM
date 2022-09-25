#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> st;

void    get(int num, int st, int ed)
{
    if (v[(st + ed) / 2] == num)
    {
        cout << (st + ed) / 2 << ' ';
        return ; 
    }
    int mid = (st + ed) / 2; 
    if (v[mid] > num)
        get(num, st, mid);
    else
        get(num, mid, ed);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, num;
    cin >> n;
    while (n--)
    {
        cin >> num;
        st.push_back(num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < st.size(); i++)
        get(st[i], 0, v.size());

    return (0);
}