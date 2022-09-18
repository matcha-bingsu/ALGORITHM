#include <bits/stdc++.h>
using namespace std;
int dwarf[9];
int sum;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 9; i++)
        cin >> dwarf[i];
    sort(dwarf, dwarf + 9);
    sum = accumulate(dwarf, dwarf + 9, 0);
    int np[9] = {0, 0, 1, 1, 1, 1, 1, 1, 1};

    do{
        int tmp_sum;
        tmp_sum = sum;
        for (int i = 0; i < 9; i++)
            if (!np[i])
                tmp_sum -= dwarf[i];
        if (tmp_sum == 100)
            break;
    }while (next_permutation(np, np + 9));

    for (int i = 0; i < 9; i++)
        if (np[i])
            cout << dwarf[i] << '\n';
    return (0);
}