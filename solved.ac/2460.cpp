#include <bits/stdc++.h>
using namespace std;
int in, out, passengers, mx;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 10; i++)
    {
        cin >> in >> out;
        passengers -= in;
        passengers += out;
        mx = max(mx, passengers);
    }
    cout << mx;
    return (0);
}