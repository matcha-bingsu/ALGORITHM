#include <bits/stdc++.h>
using namespace std;
int t, a, b, num, cnt;

void    binarysearch(vector<int> &A, vector<int> &B, int target, int st, int ed)
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
        binarysearch(A, B, target, 0, mid);
    else
        binarysearch(A, B, target, mid, ed);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        vector<int> A;
        vector<int> B;
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
            binarysearch(A, B, A[i], 0, B.size());
        cout << cnt << '\n';
    }
    return (0);
}