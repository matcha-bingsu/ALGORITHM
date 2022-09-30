#include <bits/stdc++.h>
using namespace std;
int t, a, b, num, cnt;
vector<int> A;
vector<int> B;

void    binarysearch(int target, int st, int ed)
{
    if (ed - st == 1)
    {
        if (target <= B[st])
            cnt += st;
        else 
            cnt += ed;
        return ;
    }
    int mid = (st + ed) / 2;
    if (target <= B[mid])
        binarysearch(target, 0, mid);
    else
        binarysearch(target, mid, ed);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        while (a--)
        {
            cin >> num;
            A.push_back(num);
        }
        while (b--)
        {
            cin >> num;
            B.push_back(num);
        }
        cnt = 0;
        sort(B.begin(), B.end());
        for (int i = 0; i < A.size(); i++)
            binarysearch(A[i], 0, B.size());
        cout << cnt << '\n';
        A.erase(A.begin(), A.end());
        B.erase(B.begin(), B.end());
    }
    return (0);
}