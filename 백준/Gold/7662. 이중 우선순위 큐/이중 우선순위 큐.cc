#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long     t, n, num;
    string  order;

    cin >> t;
    while (t--)
    {
        priority_queue<long, vector<long>, greater<long>>  lq;
        priority_queue<long, vector<long>, less<long>>     gq;
        unordered_multiset<long>                              chck;

        cin >> n;
        while (n--)
        {
            cin >> order >> num;
            if (order == "I")
            {
                gq.push(num);
                lq.push(num);
                chck.insert(num);
            }
            else if (order == "D")
            {
                if (num == 1)
                {
                    while (!gq.empty() && chck.find(gq.top()) == chck.end())
                        gq.pop();
                    if (!gq.empty())
                    {
                        chck.erase(chck.find(gq.top()));
                        gq.pop();
                    }
                }
                else
                {
                    while (!lq.empty() && chck.find(lq.top()) == chck.end())
                        lq.pop();
                    if (!lq.empty())
                    {
                        chck.erase(chck.find(lq.top()));
                        lq.pop();
                    }
                }
            }
        }
        while (!gq.empty() && chck.find(gq.top()) == chck.end())
            gq.pop();
        while (!lq.empty() && chck.find(lq.top()) == chck.end())
            lq.pop();
        if (gq.empty() && lq.empty())
            cout << "EMPTY\n";
        else
            cout << gq.top() << ' ' << lq.top() << '\n';
    }
    return (0);
}