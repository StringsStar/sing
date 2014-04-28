#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <algorithm>
using namespace std;

struct Gang {
	int Time;
	int Proty;
	int Slout;
};

Gang Guy[105];
int N,K,T;
int nVal=0;
int nMax=0;
int visit[105]={0};

bool cmp(const Gang& a,const Gang& b) {
	return a.Time<b.Time;
}

int main()
{
	while(scanf("%d%d%d",&N,&K,&T)!=-1) 
	{
		nMax=0;
		memset(visit,0,105*sizeof(int) );
		for(int i=1;i<=N;i++)
			cin>>Guy[i].Time;
		for(int i=1;i<=N;i++)
			cin>>Guy[i].Proty;
		for(int i=1;i<=N;i++)
			cin>>Guy[i].Slout;
		//构造一个Guy
		Guy[0].Time=Guy[0].Proty=Guy[0].Slout=0;
		sort(Guy+1,Guy+1+N,cmp);
		//let's calculate
		for(int i=1;i<=N;i++)
		{
		  visit[i]=Guy[i].Time>=Guy[i].Slout ? Guy[i].Proty : 0;
		  for(int j=1;j<i;j++)
		  {
			if(!visit[j]) continue;
			if(abs(Guy[i].Slout-Guy[j].Slout)<=Guy[i].Time-Guy[j].Time)
			  visit[i]=max(visit[j]+Guy[i].Proty,visit[i]);
		  }
		}
		int ans=0;
		for(int i=1;i<=N;i++)
		  ans=max(ans,visit[i]);
		cout<<ans<<endl;
	}
	return 0;
}
