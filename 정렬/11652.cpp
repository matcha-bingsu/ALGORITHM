// https://www.acmicpc.net/problem/11652 (카드)
#include <bits/stdc++.h>
using namespace std;
long long   n, cnt, mxcnt;
long long   val = 9223372036854775807; 
long long   input[100001];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input[i];
    
    sort(input, input + n);
    input[n] = 9223372036854775807;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || input[i] == input[i - 1])
            cnt++;
        else
        {
            if (cnt > mxcnt)
            {
                val = input[i - 1];
                mxcnt = cnt;
            }
            cnt = 1;
        }
    }
    cout << val;
    return (0);
}