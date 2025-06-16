#include <bits/stdc++.h>

using namespace std;

int t, n, m, k, minGoldLost, tGold;
//0 - empty
//1 - gold
//-1 blocked
int map[509][509];

int obj(char& x)
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
    return 0;
}