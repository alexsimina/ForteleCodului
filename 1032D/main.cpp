#include <bits/stdc++.h>

using namespace std;

struct coords
{
    int x, y;
};

int t, n, a[49], b[49], nrOp;
coords freq[109], operatii[1809];

void mutare(int start, int end, int curr[], int tipOp)
{

    if (start < end)
    {
        for (int i = start; i < end; i++)
        {
            nrOp++;
            operatii[nrOp] = {tipOp, i};
            freq[curr[i + 1]].y--;
            freq[curr[i]].y++;
            swap(curr[i], curr[i + 1]);
        }
    }
    else
    {
        for (int i = start - 1; i >= end; i--)
        {
            nrOp++;
            operatii[nrOp] = {tipOp, i};
            freq[curr[i + 1]].y--;
            freq[curr[i]].y++;
            swap(curr[i], curr[i + 1]);
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        nrOp = 0;
        memset(freq, 0, sizeof(freq));
        memset(operatii, 0, sizeof(operatii));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            freq[a[i]].x = 1;
            freq[a[i]].y = i;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            freq[b[i]].x = 2;
            freq[b[i]].y = i;
        }

        for (int i = 1; i <= n; i++)
        {
            int start = freq[i].y;
            if (freq[i].x == 1)
            {
                mutare(start, i, a, 1);
            }
            else
            {
                mutare(start, i, b, 2);
                nrOp++;
                operatii[nrOp] = {3, i};
                swap(freq[a[i]].x, freq[b[i]].x);
                swap(a[i], b[i]);
            }
        }

        for (int i = n + 1; i <= 2 * n; i++)
        {
            int start = freq[i].y;
            if (freq[i].x == 1)
            {
                mutare(start, i - n, a, 1);
                nrOp++;
                operatii[nrOp] = {3, i - n};
                swap(freq[a[i - n]].x, freq[b[i - n]].x);
                swap(a[i - n], b[i - n]);
            }
            else
            {
                mutare(start, i - n, b, 2);
            }
        }

        cout << nrOp << '\n';
        for (int i = 1; i <= nrOp; i++)
        {
            cout << operatii[i].x << ' ' << operatii[i].y << '\n';
        }
    }
    return 0;
}