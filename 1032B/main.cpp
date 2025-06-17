#include <bits/stdc++.h>

using namespace std;

int t, n, freq[128];
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        memset(freq, 0, sizeof(freq));
        cin >> n >> s;
        for (int i = 0; i < n; i++)
        {
            freq[s[i]]++;
        }

        int yes = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (freq[s[i]] > 1)
            {
                cout << "Yes\n";
                yes = 1;
                break;
            }
        }

        if (!yes)
            cout << "No\n";
    }
    return 0;
}