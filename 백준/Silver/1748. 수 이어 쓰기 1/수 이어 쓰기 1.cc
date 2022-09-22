#include <bits/stdc++.h>
using namespace std;
int num, ans;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> num;

    int     standard = 10;
    int     numlen = 1;
    string  pre = "";
    string  nine = "9";

    while (standard <= num)
    {
        ans += numlen * (atoi(nine.c_str()) - atoi(pre.c_str()));
        standard *= 10;
        numlen++;
        pre.append("9");
        nine.append("9");
    }
    ans += numlen * (num - atoi(pre.c_str()));
    cout << ans << '\n';
    return (0);
}