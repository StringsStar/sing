#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int D[100][100];
int Pack[100];
int nRow;

int GetMostPack()
{
  int lMax=0;
  for(int i=0;i<nRow;i++)
  {
	int nSum=Pack[i];
    for(int j=i+1;j<nRow;j++)	
	{ nSum+=Pack[j]; lMax=max(lMax,nSum); }
  }
  return lMax;
}

int main()
{
  while(scanf("%d",&nRow)!=-1)
  {
	int nMax=0;
	for(int i=0;i<nRow;i++)
	  for(int j=0;j<nRow;j++)
		scanf("%d",&D[i][j]);
	
	//calc n*N List
	for(int j=0;j<nRow;j++)
	  for(int k=1;k<=nRow;k++)
	  {
	    if(j+k>nRow)
		  break;

		for(int i=0;i<nRow;i++)
		{
		  int nSum=0;
		  for(int t=j;t<j+k;t++)
			nSum+=D[i][t];
		  Pack[i]=nSum;
		}
		int nCur=GetMostPack();
		nMax=max(nCur,nMax);
	  }
	printf("%d\n",nMax);
  }
}
