#include <bits/stdc++.h>

using namespace std;

struct puncte
{
    int max, x, y;
};

int t, n, m, freq[109];

int main()
{
    cin >> t;
    while (t--)
    {
        puncte max1{}, max2{};
        max1.max = max2.max = -1;
        cin >> n >> m;
        vector<vector<int>> v(n + 2, vector<int>(m + 2));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> v[i][j];
                if (v[i][j] > max1.max)
                {
                    max2 = max1;
                    max1.max = v[i][j];
                    max1.x = i;
                    max1.y = j;
                }
                else if (v[i][j] > max2.max || (v[i][j] == max2.max && i != max1.x && j != max1.y))
                {
                    max2.max = v[i][j];
                    max2.x = i;
                    max2.y = j;
                }
            }

        if (max2.max == -1)
            max2 = max1;

        int rez1 = -1, rez2 = -1;

        for (int i = 1; i <= n; i++)
        {
            v[i][max1.y]--;
        }
        for (int j = 1; j <= m; j++)
        {
            v[max2.x][j]--;
        }
        v[max2.x][max1.y]++;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                rez1 = max(rez1, v[i][j]);
        }
        for (int i = 1; i <= n; i++)
        {
            v[i][max1.y]++;
        }
        for (int j = 1; j <= m; j++)
        {
            v[max2.x][j]++;
        }
        v[max2.x][max1.y]--;




        for (int i = 1; i <= n; i++)
        {
            v[i][max2.y]--;
        }
        for (int j = 1; j <= m; j++)
        {
            v[max1.x][j]--;
        }
        v[max1.x][max2.y]++;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                rez2 = max(rez2, v[i][j]);
        }

        cout << min(rez1, rez2) << '\n';

    }
    return 0;
}