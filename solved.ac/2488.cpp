#include <bits/stdc++.h>
using namespace std;
int n;
int mx = -2147483648;
int mn = 2147483647;
int sig[4];
vector<int> v;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    for (int i = 0; i < 4; i++)
        cin >> sig[i];
    for (int i = 0; i < 4; i++)
        while (sig[i]--)
            v.push_back(i);
    
    do{
        int total = numbers[0];
        for (int i = 1; i < n; i++)
        {
            if (v[i - 1] == 0)
                total += numbers[i];
            else if (v[i - 1] == 1)
                total -= numbers[i];
            else if (v[i - 1] == 2)
                total *= numbers[i];
            else
            {
                if (total < 0)
                {
                    total = abs(total) / numbers[i];
                    total *= -1;
                }
                else
                    total /= numbers[i];
            }
        }
        mx = max(mx, total);
        mn = min(mn, total);
    }while (next_permutation(v.begin(), v.end()));
    cout << mx << '\n' << mn;
    return (0);
}