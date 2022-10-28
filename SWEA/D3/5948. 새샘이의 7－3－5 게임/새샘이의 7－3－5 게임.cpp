#include <bits/stdc++.h>
using namespace std;

void init(int *arr, vector<int> &v)
{
    for (int i = 0; i < 7; i++)
        cin >> arr[i];
    
    for (int i = 0; i < 7; i++)
    {
        if (i < 3)
            v.push_back(0);
        else
            v.push_back(1);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        int arr[7];
        vector<int> v;
        vector<int> ans;

        init(arr, v);
        do
        {
            int total = 0;
            for (int i = 0; i < 7; i++)
            {
                if (!v[i])
                    total += arr[i];
            }
            ans.push_back(total);
        } while (next_permutation(v.begin(), v.end()));

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        cout << '#' << cur_case << ' ' << ans[ans.size() - 5] << '\n';
    }
    return (0);
}