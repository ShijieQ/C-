#include <bits/stdc++.h>
using namespace std;
char q[12][12], d[12][12];
typedef struct Q
{
    int x, y;
    char ch;
    Q() {}
} Q;
Q ccc[10];
int main()
{
    int n, bx, by;
    while (cin >> n >> bx >> by &&( n || bx|| by))
    {
        bool die = false;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                d[i][j] = '#';
                if (i == 0 || j == 0)
                    q[i][j] = '~';
                else if (i > 10 || j >= 10)
                    q[i][j] = '~';
                else
                    q[i][j] = '#';
            }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> ccc[i].ch >> ccc[i].x >> ccc[i].y;
            if(ccc[i].x == bx && ccc[i].y == by)
                die = true;
            d[ccc[i].x][ccc[i].y] = ccc[i].ch;
        }
        for (int it = 0; it < n; it++)
        {
            if (die)
                break;
            int i = ccc[it].x, j = ccc[it].y;
            if (d[i][j] == 'H')
            {
                if ((d[i][j - 1] == '#') && j - 2 > 0)
                {
                    if (i - 1 > 0)
                    {
                        q[i - 1][j - 2] = 'x';
                    }
                    if (i + 1 <= 10)
                    {
                        q[i + 1][j - 2] = 'x';
                    }
                }
                if ((d[i][j + 1] == '#') && j + 2 < 10)
                {
                    if (i - 1 > 0)
                    {
                        q[i - 1][j + 2] = 'x';
                    }
                    if (i + 1 <= 10)
                    {
                        q[i + 1][j + 2] = 'x';
                    }
                }
                if ((d[i - 1][j] == '#') && i - 2 > 0)
                {
                    if (j - 1 > 0)
                    {
                        q[i - 2][j - 1] = 'x';
                    }
                    if (j + 1 < 10)
                    {
                        q[i - 2][j + 1] = 'x';
                    }
                }
                if ((d[i + 1][j] == '#') && i + 2 <= 10)
                {
                    if (j - 1 > 0)
                    {
                        q[i + 2][j - 1] = 'x';
                    }
                    if (j + 1 < 10)
                    {
                        q[i + 2][j + 1] = 'x';
                    }
                }
            }
            else if (d[i][j] == 'C')
            {
                int xx = 0, ll = 0, rr = 100, yy = 100;
                for (int aa = i - 1; aa > 0; aa--)
                {
                    if (d[aa][j] != '#')
                    {
                        xx = aa - 1;
                        break;
                    }
                }
                for (; xx > 0; xx--)
                {
                    q[xx][j] = 'x';
                    if (d[xx][j] != '#')
                    {
                        break;
                    }
                }
                for (int aa = 0; aa <= 10; aa++)
                {
                    if (d[aa][j] != '#')
                    {
                        yy = aa + 1;
                        break;
                    }
                }
                for (; yy <= 10; yy++)
                {
                    q[yy][j] = 'x';
                    if (d[yy][j] != '#')
                    {
                        q[yy][j] = 'x';
                        break;
                    }
                }
                for (int aa = j - 1; aa > 0; aa--)
                {
                    if (d[i][aa] != '#')
                    {
                        ll = aa - 1;
                        break;
                    }
                }
                for (; ll > 0; ll--)
                {
                    q[i][ll] = 'x';
                    if (d[i][ll] != '#')
                    {
                        break;
                    }
                }
                for (int aa = j + 1; aa <= 10; aa++)
                {
                    if (d[i][aa] != '#')
                    {
                        rr = aa + 1;
                        break;
                    }
                }
                for (; rr < 10; rr++)
                {
                    q[i][rr] = 'x';
                    if (d[i][rr] != '#')
                    {
                        break;
                    }
                }
            }
            else if (d[i][j] == 'R' || d[i][j] == 'G')
            {
                for (int xx = i + 1; xx <= 10; xx++)
                {
                    if (d[xx][j] == '#')
                    {
                        q[xx][j] = 'x';
                    }
                    else
                    {
                        q[xx][j] = 'x';
                        break;
                    }
                }
                for (int xx = i - 1; xx > 0; xx--)
                {
                    if (d[xx][j] == '#')
                    {
                        if (xx == bx && j == by && d[i][j] == 'G')
                            die = true;
                        q[xx][j] = 'x';
                    }
                    else
                    {
                        q[xx][j] = 'x';
                        break;
                    }
                }
                for (int yy = j + 1; yy < 10; yy++)
                {
                    if (d[i][yy] == '#')
                    {
                        q[i][yy] = 'x';
                    }
                    else
                    {
                        q[i][yy] = 'x';
                        break;
                    }
                }
                for (int yy = j - 1; yy > 0; yy--)
                {
                    if (d[i][yy] == '#')
                    {
                        q[i][yy] = 'x';
                    }
                    else
                    {
                        q[i][yy] = 'x';
                        break;
                    }
                }
            }
        }
        // for (int i = 0; i <= 10; i++)
        // {
        //     for (int j = 0; j <= 11; j++)
        //     {
        //         cout << q[i][j] << ' ';
        //     }
        //     puts("");
        // }
        // puts("");
        // for (int i = 0; i <= 10; i++)
        // {
        //     for (int j = 0; j <= 11; j++)
        //     {
        //         cout << d[i][j] << ' ';
        //     }
        //     puts("");
        // }
        if (q[bx - 1][by] == '#' && bx - 1 > 0)
            die = true;
        if (q[bx + 1][by] == '#' && bx + 1 < 4)
            die = true;
        if (q[bx][by - 1] == '#' && by - 1 > 3)
            die = true;
        if (q[bx][by + 1] == '#' && by + 1 < 7)
            die = true;

        if (die)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
