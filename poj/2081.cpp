#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
const int N=500010;
int ch[N];
bool vis[N*10];
void init()
{
    int i,j;
    memset(vis,false,sizeof(vis));
    memset(ch,0,sizeof(ch));
    vis[0]=vis[1]=vis[3]=true;
    ch[0]=0;ch[1]=1;
    for(i=2;i<N;i++)
    {
        ch[i]=ch[i-1]-i;
        if(ch[i]<1||vis[ch[i]])
            ch[i]=ch[i-1]+i;
        vis[ch[i]]=true;
    }
    return ;           
}
int main()
{
    int i,j,k;
    init();
    while(scanf("%d",&k),k!=-1)
        printf("%d\n",ch[k]);
    return 0;
}
     
