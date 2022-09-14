#include <bits/stdc++.h>
using namespace std;
int num;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int number = 1; number <= 10; number++)
    {
        int cnt = 0;
        cin >> num;
        int input[num];

        for (int i = 0; i < num; i++)
            cin >> input[i];
        for (int i = 2; i < num - 2; i++)
        {
            if (input[i - 2] >= input[i] || input[i - 1] >= input[i] || input[i + 1] >= input[i] || input[i + 2] >= input[i])
                continue;
            else
                cnt += min(input[i] - max(input[i - 1], input[i - 2]), input[i] - max(input[i + 1], input[i + 2]));
        }
        cout << '#' << number << ' ' << cnt << '\n';
    }
    return (0);
}
