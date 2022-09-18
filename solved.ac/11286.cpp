#include <bits/stdc++.h>
using namespace std;
int n, num;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    cin >> n;
    while (n--)
    {
        cin >> num;
        if (num == 0)
        {
            if (q.empty())
                cout << "0\n";
            else
            {
                cout << q.top().second << '\n';
                q.pop();
            }
        }
        else
            q.push({abs(num), num});
    }
    return (0);
}