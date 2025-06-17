#include <bits/stdc++.h>

using namespace std;

int t, n, s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        int minn;
        cin >> minn;
        for (int i = 2; i < n; i++)
        {
            int x;
            cin >> x;
        }
        int maxx;
        if (n == 1)
            maxx = minn;
        else cin >> maxx;

        int rez1 = abs(maxx - s) + maxx - minn;
        int rez2 = abs(minn - s) + maxx - minn;

        cout << min(rez1, rez2) << '\n';
    }
    return 0;
}