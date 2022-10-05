#include <bits/stdc++.h>
using namespace std;
int arr[21][21];

int get_sum(vector<int>  v)
{
    int tmp = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
            tmp += arr[v[i]][v[j]] + arr[v[j]][v[i]];
    }
    return (tmp);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    int mn = 987654321;
    cin >> n;
    int half_arr[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    for(int i = 0; i < n; i++)
    {
        if (i < n / 2)
            half_arr[i] = 0;
        else
            half_arr[i] = 1;
    }

    do{
        vector<int> start;
        vector<int> link;
        for (int i = 0; i < n; i++)
        {
            if (!half_arr[i])
                start.push_back(i);
            else
                link.push_back(i);
        }
        mn = min(mn, abs(get_sum(start) - get_sum(link)));
    }while (next_permutation(half_arr, half_arr + n));
    cout << mn;
    return (0);
}