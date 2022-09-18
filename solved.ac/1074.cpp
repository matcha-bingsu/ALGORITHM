// https://www.acmicpc.net/problem/1074
#include <bits/stdc++.h>
using namespace std;

int backtracking(int n, int r, int c)
{
    if (n == 1)
        return (0);
    
    if (r < n / 2 && c < n / 2)
        return (backtracking(n / 2, r, c));
    else if (r < n / 2 && c >= n / 2)
        return(pow(n / 2, 2) + backtracking(n / 2, r, c - (n / 2)));
    else if (r >= n / 2 && c < n / 2)
        return ((n / 2 * n) + backtracking(n / 2, r - (n / 2), c));
    else
        return (pow(n / 2, 2) + (n / 2 * n) + backtracking(n / 2, r - (n / 2), c - (n / 2)));
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
   
    int n, r, c;
    cin >> n >> r >> c;
    cout << backtracking(2 << (n - 1), r, c);
    
    return (0);
}
