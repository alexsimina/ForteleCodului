#include <bits/stdc++.h>

using namespace std;


int t, l[4], b[4];

bool tries()
{
    int lastl[4] = {0, l[1], l[2], l[3]};
    int lastb[4] = {0, b[1], b[2], b[3]};
    if (l[1] == l[2])
        {
            b[1] += b[2];
            if (l[1] == l[3])
            {
                b[1] += b[3];
                if (l[1] == b[1])
                {
                    return true;
                }
            }
            memcpy(b, lastb, sizeof(b));
            memcpy(l, lastl, sizeof(l));

            b[1] += b[2];
            if (b[1] == b[3])
            {
                l[1] += l[3];
                if (l[1] == b[1])
                {
                    return true;

                }
            }
        }

    memcpy(b, lastb, sizeof(b));
    memcpy(l, lastl, sizeof(l));


        if (b[1] == b[2])
        {
            l[1] += l[2];
            if (b[1] == b[3])
            {
                l[1] += l[3];
                if (l[1] == b[1])
                {
                    return true;

                }
            }
            memcpy(b, lastb, sizeof(b));
            memcpy(l, lastl, sizeof(l));

            l[1] += l[2];
            if (l[1] == l[3])
            {
                b[1] += b[3];
                if (l[1] == b[1])
                {
                    return true;

                }
            }
        }

        memcpy(b, lastb, sizeof(b));
        memcpy(l, lastl, sizeof(l));

    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {

        cin >> l[1] >> b[1] >> l[2] >> b[2] >> l[3] >> b[3];
        int lastl[4] = {0, l[1], l[2], l[3]};
        int lastb[4] = {0, b[1], b[2], b[3]};
        if (tries())
        {
            cout << "YES\n";
            continue;
        }

        memcpy(b, lastb, sizeof(b));
        memcpy(l, lastl, sizeof(l));

        swap(l[2], l[3]);
        swap(b[2], b[3]);

        if (tries())
        {
            cout << "YES\n";
            continue;
        }

        memcpy(b, lastb, sizeof(b));
        memcpy(l, lastl, sizeof(l));

        swap(l[1], l[2]);
        swap(b[1], b[2]);

        if (tries())
        {
            cout << "YES\n";
            continue;
        }

        memcpy(b, lastb, sizeof(b));
        memcpy(l, lastl, sizeof(l));

        swap(l[1], l[3]);
        swap(b[1], b[3]);

        if (tries())
        {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";

    }
    return 0;
}