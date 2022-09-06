#include <bits/stdc++.h>
using namespace std;
int F, X, Y, sf, sx, sy, ef, ex, ey ,flag;
int dx[6] = {0, 0, 0, -1, 0, 1};
int dy[6] = {0, 0, -1, 0, 1, 0};

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (1)
    {
        cin >> F >> X >> Y;
        if (!F && !X && !Y)
            return (0);
        
        //케이스 초기화
        int arr[F][X][Y];
        fill((int *)arr , (int *)(arr + F), 0);
        for (int f = 0; f < F; f++)
        {
            for (int i = 0; i < X; i++)
            {
                string s;
                int    j = 0;
                cin >> s;
                for (auto c : s)
                {
                    if (c == '.')
                        arr[f][i][j] = -1;
                    else if (c == '#')
                        arr[f][i][j] = -2;
                    else if (c == 'S')
                    {
                        sf = f;
                        sx = i;
                        sy = j;
                    }
                    else
                    {
                        ef = f;
                        ex = i;
                        ey = j;
                    }
                    j++;
                }
            }
        }

        //계산
        queue<tuple<int, int, int>> q;
        flag = 0;
        q.push({sf, sx, sy});
        while (!q.empty())
        {
            int cf, cx, cy;
            tie(cf, cx, cy) = q.front();
            if (cf == ef && cx == ex && cy == ey)
            {
                cout << "Escaped in " << arr[cf][cx][cy] << " minute(s).\n";
                flag++;
                break;
            }
            q.pop();
            for (int i = 0; i < 6; i++)
            {
                int nf = cf;
                if (i == 0)
                    nf = cf + 1;
                else if (i == 1)
                    nf = cf - 1;
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nf < 0 || nf >= F || nx < 0 || nx >= X || ny < 0 || ny >= Y)
                    continue;
                if (arr[nf][nx][ny] > 0 || arr[nf][nx][ny] == -2)
                    continue;
                arr[nf][nx][ny] = arr[cf][cx][cy] + 1;
                q.push({nf, nx, ny});
            }
        }
        if (!flag)
            cout << "Trapped!\n";
    }
    return (0);
}