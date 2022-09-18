// https://www.acmicpc.net/problem/1259 (팰린드럼수)
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string  N;
    string  tmp;

    while (N != "0")
    {
        cin >> N;
        tmp = N;
        reverse(tmp.begin(), tmp.end());
        if (N == "0")
            break;
        if (N == tmp)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return(0);
}
