#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, N;
    int score[100];
    bool visited[10001];
    vector<int> canScore;

    cin >> T;
    for (int cur_case = 1; cur_case <= T; cur_case++)
    {
        int ans = 0;
        fill(score, score + 100, 0);
        fill(visited, visited + 10001, false);
        canScore.clear();

        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> score[i];

        canScore.push_back(0);
        visited[0] = true;

        for (int i = 0; i < N; i++)
        {
            int v_size = canScore.size();
            for (int j = 0; j < v_size; j++)
            {
                int newScore = canScore[j] + score[i];
                if (!visited[newScore])
                {
                    canScore.push_back(newScore);
                    visited[newScore] = true;
                }
            }
        }
        ans = canScore.size();

        cout << '#' << cur_case << ' ' << ans << '\n';
    }
    return (0);
}