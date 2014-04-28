#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 105

int n, d;
bool vis[maxn];

int main()
{
    while (scanf("%d%d", &n, &d), n | d)
    {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < d; i++)
            for (int i = 0; i < n; i++)
            {
                int a;
                scanf("%d", &a);
                if (!a)
                    vis[i] = true;
            }
        bool ok = false;
        for (int i = 0; i < n; i++)
            if (!vis[i])
            {
                ok = true;
                break;
            }
        if (ok)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
