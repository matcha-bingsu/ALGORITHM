#include <bits/stdc++.h>
using namespace std;
int cnt;
int alpha1[26];
int alpha2[26];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string a, b;
    cin >> a >> b;
    for (auto c : a)
        alpha1[c - 97]++;
    for (auto c : b)
        alpha2[c - 97]++;
    for (int i = 0; i < 26; i++)
        cnt += abs(alpha1[i] - alpha2[i]);
    cout << cnt;
    return (0);
}