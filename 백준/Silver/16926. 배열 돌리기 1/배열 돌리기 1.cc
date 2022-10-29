#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int table[305][305]; 

void rotate(int si, int sj, int ei, int ej) {
    int temp = table[si][sj];
    
    for(int j = sj; j < ej; j++)
        table[si][j] = table[si][j+1];

    for(int i = si; i < ei; i++)
        table[i][ej] = table[i+1][ej];

    for(int j = ej; sj < j; j--)
        table[ei][j] = table[ei][j-1];

    for(int i = ei; si+1 < i; i--)
        table[i][sj] = table[i-1][sj];

    table[si+1][sj] = temp; 
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >> r;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> table[i][j];

    while(r--)
    {
        int si = 1;
        int sj = 1;
        int ei = n;
        int ej = m;
        
        while(si < ei && sj < ej)
        {
            rotate(si, sj, ei, ej);
            si++;
            sj++;
            ei--;
            ej--;
        }   
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout << table[i][j] << " ";
        cout << endl;
    }
    return (0);
}