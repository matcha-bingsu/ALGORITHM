// https://www.acmicpc.net/problem/15688 (수 정렬하기 5)
#include <bits/stdc++.h>
using namespace std;
int N, num;
int keep[2000001];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    while (N--)
    {
        cin >> num;
        keep[num + 1000000]++;
    }

    for (int i = 0; i <= 2000000; i++)
    {
        if (keep[i])
            for (int j = 0; j < keep[i]; j++)
                cout << i - 1000000 << '\n';
    }
    return (0);
}