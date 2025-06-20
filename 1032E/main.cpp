#include <bits/stdc++.h>

using namespace std;

int l[10], r[10], t, lintg, rintg;

//1 - mic
//2 - intre
//3 - mare
//4 - acelasi

int solve(int& len, int poz, int type)
{
    if (poz > len)
        return 0;

    int rez = 1e9;
    if (l[poz] == r[poz] && type == 4)
    {
        rez = 2 + solve(len, poz + 1, 4);
    }
    else if (type == 2)
    {
        rez = min(rez, solve(len, poz + 1, type));
    }
    else if (type == 1)
    {
        rez = 1 + solve(len, poz + 1, 1);
        if (l[poz] + 1 <= 9)
            rez = min(rez, solve(len, poz + 1, 2));

    }
    else if (type == 3)
    {
        rez = 1 + solve(len, poz + 1, 3);
        if (0 <= r[poz] - 1)
            rez = min(rez, solve(len, poz + 1, 2));

    }
    else
    {
        rez = 1 + solve(len, poz + 1, 1);
        rez = min(rez, solve(len, poz + 1, 3) + 1);
        if (l[poz] + 1 <= r[poz] - 1)
            rez = min(rez, solve(len, poz + 1, 2));
    }

    return rez;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {

        cin >> lintg >> rintg;
        int ln = log10(rintg) + 1;
        int lsize = log10(lintg) + 1;
        while (lintg)
        {
            l[lsize] = lintg % 10;
            lintg /= 10;
            lsize--;
        }


        int rsize = log10(rintg) + 1;
        while (rintg)
        {
            r[rsize] = rintg % 10;
            rintg /= 10;
            rsize--;
        }

        cout << solve(ln, 1, 4) << '\n';
    }
    return 0;
}