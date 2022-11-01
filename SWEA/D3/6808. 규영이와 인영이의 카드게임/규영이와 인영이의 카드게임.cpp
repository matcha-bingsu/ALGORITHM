#include <bits/stdc++.h>
using namespace std;
int win, lose;
bool chck[19];
int gu[9], yin[9];

void    init()
{
    win = 0;
    lose = 0;
    fill(chck, chck + 19, 0);
    fill(gu, gu + 9, 0);
    fill(yin, yin + 9, 0);
}

void    input()
{
    int number;
    int j = 0;

    for (int i = 0; i < 9; i++)
    {
        cin >> number;
        gu[i] = number;
        chck[number] = true;
    }

    for (int i = 1; i <= 18; i++)
    {
        if (!chck[i])
            yin[j++] = i;
    }
}

void    baegopa(int tmp[], int idx, int gu_total, int yin_total)
{
    if (idx == 9)
    {
        if (gu_total > yin_total)
            win++;
        else if (gu_total < yin_total)
            lose++;
        return ;
    }

    for (int i = 0; i < 9; i++)
    {
        if (!chck[yin[i]])
        {
            tmp[idx] = yin[i];
            chck[yin[i]] = true;
            if (tmp[idx] < gu[idx])
                baegopa(tmp, idx + 1, gu_total + tmp[idx] + gu[idx], yin_total);
            else if (tmp[idx] > gu[idx])
                baegopa(tmp, idx + 1, gu_total, yin_total + tmp[idx] + gu[idx]);
            chck[yin[i]] = false;
        }
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
        int tmp[9];

        init();
        input();
        baegopa(tmp, 0, 0, 0);
        cout << '#' << cur_case << ' ' << win << ' ' << lose << '\n';
    }
    return (0);
}