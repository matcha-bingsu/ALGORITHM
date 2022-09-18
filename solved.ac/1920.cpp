// https://www.acmicpc.net/problem/1920 (수 찾기)
#include <bits/stdc++.h>
using namespace std;
int n, m;
int input[100001];
int here[100001];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> here[i];
    
    sort(input, input + n);
    
    for (int i = 0; i < m; i++)
    {
        int st = 0;
        int flag = 0;
        int en = n;
        while (en - st != 0)
        {
            int mid = (en + st) / 2;
            if (here[i] < input[mid])
                en = mid;
            else if (here[i] > input[mid])
                st = mid + 1;
            else
            {
                cout << "1\n";
                flag++;
                break;
            }
        }
        if (!flag)
            cout << "0\n";
    }
    return (0);
}