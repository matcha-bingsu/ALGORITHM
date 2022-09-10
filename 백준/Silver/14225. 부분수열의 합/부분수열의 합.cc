#include <bits/stdc++.h>
using namespace std;
int n, num;
int chck[2000001];
vector<int> v;
void    make(int number)
{
    vector<int> tmp;
    for (int i = 1; i <= n; i++)
    {
        if (i <= number)
            tmp.push_back(0);
        else
            tmp.push_back(1);
    }
    do{
        int num_tmp = 0;
        for(int i = 0; i < n; i++)
            if (!tmp[i])
                num_tmp += v[i];
        chck[num_tmp] = 1;
    }while (next_permutation(tmp.begin(), tmp.end()));
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    for(int i = 1; i <= n; i++)
        make(i);
    for (int i = 1; i <= accumulate(v.begin(), v.end(), 0) + 1; i++)
    {
        if (!chck[i])
        {
            cout << i;
            return (0);
        }
    }
    return (0);
}