#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string  a, b;
    cin >> a >> b;

    int length_a = a.size();
    int length_b = b.size();
    int numtoadd = length_b - length_a;
    int m = INT_MAX;

    for (int i = 0; i < numtoadd + 1; i++)
    {
        int cnt = 0;
        for (int j = 0; j < length_a; j++)
            if (a[j] != b[i + j])
                cnt++;
        m = min(cnt, m);
    }
    cout << m;
    return (0);
}