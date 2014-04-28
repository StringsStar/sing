#include <iostream> 
#include <cstdio> 
#include <algorithm> 
using namespace std;
int D[100][100]={0};
int V[100][100]={0};
int nRow,nCol;

struct Point {
  int x;
  int y;
};

void GetNextLowest(Point* p)
{
  int nH=10001;
 
  for(int i=0;i<nRow;i++)
	for(int j=0;j<nCol;j++)
	{
	  //已经选中的直接去掉
	  if(V[i][j]==0) {
		nH=min(nH,D[i][j]);
		if(nH==D[i][j]) {p->x=i; p->y=j; }
	  }
	}
  	
}
int main()
{
  while(scanf("%d %d",&nRow,&nCol)!=-1)
  {
	int nMax=0;
	for(int i=0;i<nRow;i++)
	  for(int j=0;j<nCol;j++)
		scanf("%d",&D[i][j]);

	for(int i=0;i<nRow*nCol;i++)
	{
	  Point P;
	  int nCur=0;
	  GetNextLowest(&P);
	  int N=D[P.x][P.y];
	  if(P.x>=1)
		if(D[P.x-1][P.y]<N)
			nCur=max(V[P.x-1][P.y],nCur);
	  if(P.x<=nRow-2)
		if(D[P.x+1][P.y]<N)
			nCur=max(V[P.x+1][P.y],nCur);
	  if(P.y>=1)
		if(D[P.x][P.y-1]<N)
			nCur=max(V[P.x][P.y-1],nCur);
	  if(P.y<=nCol-2)
		if(D[P.x][P.y+1]<N)
			nCur=max(V[P.x][P.y+1],nCur);

	  V[P.x][P.y] = nCur+1;
	}

	//Get Max
	int ans=0;
	for(int i=0;i<nRow;i++)
	  for(int j=0;j<nCol;j++)
		ans = max(ans,V[i][j]);

	printf("%d\n",ans);
  }
}
