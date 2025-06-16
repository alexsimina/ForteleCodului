#include <bits/stdc++.h>

using namespace std;

struct Coords
{
    int x, y;
};

int t, n, m, k, minGoldLost, tGold;
//0 - empty
//1 - gold
//-1 blocked
int mine[509][509], gold[509][509];

int obj(char x)
{
    switch (x)
    {
        case '#':
            return -1;
        case '.':
            return 0;
        case 'g':
            return 1;
    }

    return -2;
}

int main()
{
    cin >> t;
    while (t--)
    {
        tGold = 0;
        minGoldLost = 1e9;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
        {
            char ch;
            for (int j = 1; j <= m; j++)
            {
                cin >> ch;

                mine[i][j] = obj(ch);
                if (mine[i][j] == 1)
                {
                    tGold++;
                    gold[i][j] = 1;
                }

                gold[i][j] += gold[i - 1][j] + gold[i][j - 1] - gold[i - 1][j - 1];

            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                Coords curr = {i, j};
                if (mine[curr.x][curr.y] == 0)
                {
                    Coords jos_st = {i + k - 1, j - k};
                    int valjs = 0;
                    valjs = gold[min(n, jos_st.x)][max(0, jos_st.y)];

                    Coords sus_dr = {i - k, j + k - 1};
                    int valsd = 0;
                    valsd = gold[max(0, sus_dr.x)][min(m, sus_dr.y)];

                    Coords ss = {i - k, j - k};
                    int valss = 0;
                    valss = gold[max(0, ss.x)][max(0, ss.y)];

                    Coords uu = {i + k - 1, j + k - 1};
                    int valuu = 0;
                    valuu = gold[min(uu.x, n)][min(uu.y, m)];

                    int goldBoomed = valuu - valjs - valsd + valss;
                    minGoldLost = min(minGoldLost, goldBoomed);
                }
            }
        }

        cout << max(0, tGold - minGoldLost) << '\n';

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                gold[i][j] = mine[i][j] = 0;
    }
    return 0;
}