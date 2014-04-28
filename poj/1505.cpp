#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
using namespace std;

int S[510];
int F[510][510];
const int inf=1000000000;
int main()
{
  int Case,N,P;
  scanf("%d",&Case);
  while(Case--)
  {
	memset(S,0,sizeof(S));
	memset(F,0,sizeof(F));
	int Page;
    scanf("%d %d",&N,&P);
	for(int i=1;i<=N;i++)
	{
	  cin>>Page;
	  S[i]=S[i-1]+Page;
	  F[1][i]=F[1][i-1]+Page;
	  F[0][i]=Page;
	}

	for(int i=2;i<=P;i++)
	  for(int j=i;j<=N-P+i;j++)
	  {
		int nCur=S[N];
		for(int k=i-1;k<=j-1;k++)
		{
		  int nMax=max(F[i-1][k],S[j]-S[k]);
		  nCur=min(nMax,nCur);
		}
		F[i][j]=nCur;
	  }

	//then output<F4>
	int O[510];
	int nLoop=-1;
	int nPer=P;
	int nTop=F[P][N];
	int nSum=0;
	for(int i=N;i>=1;i--)
	{
	  nSum+=F[0][i];

	  if(nSum>nTop) {
		O[++nLoop]=i;
		nPer--;
		nSum=F[0][i];
	  } 

	  if(i-1==nPer-1) {
		for(int j=nPer-1;j>=1;j--)
		  O[++nLoop]=j;
		break; //end loop
	  }	
	}	

	int nCur=0;
	int nPut=0;
	for(int i=nLoop;i>=0;i--)
	{
	  int Num=O[i]-nCur;
	  for(int j=0;j<Num;j++)	
		printf("%d ",F[0][++nPut]);
	  printf("/ ");
	  nCur=O[i];
	}
	for(int i=nPut+1;i<=N-1;i++)
	  printf("%d ",F[0][i]);
	printf("%d\n",F[0][N]);
  }
}
