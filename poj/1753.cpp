#include <iostream>
#include <string>
#include <queue>

using namespace std;
int Board[4][4];
int parent[65535]={0};

int Flip(int nV,int nIndex)
{
	int nXor = 0;
	nXor |= 1<<nIndex;
	if( (nIndex+1)%4 != 0)
		nXor |= (1<<(nIndex+1));
	if((nIndex%4 !=0))
		nXor |= (1<<(nIndex-1));
	if((nIndex+4) < 16)
		nXor |= (1<<(nIndex+4));	
	if((nIndex-4) >= 0)
		nXor |= (1<<(nIndex-4) );
	return nV ^ nXor;
}

int bfs(int nHead)
{
	std::queue<int>		Q;
	Q.push(nHead);
	while(!Q.empty() )
	{
		int nV = Q.front();
		Q.pop();
		for(int i=0 ; i < 16 ; i++) {
			int nRes = Flip(nV , i);
			if(nRes==0 || nRes==65535) {
				parent[nRes] = nV;
				return nRes;			
			}
			if(parent[nRes]==0) {
				parent[nRes] = nV;
				Q.push(nRes);
			}
		}
	}
	return -1;
}

int GetDepth(int nDst)
{
	int nTemp=nDst;
	int nLoop=0;
	while(parent[nTemp] != -1)
	{
		nTemp = parent[nTemp];
		nLoop++;
	}
	return nLoop;
}

int GetNum()
{
	int nNum=0;
	int nLoop=16;
	char c;
	while(nLoop--)
	{
		cin>>c;
		if(c=='b')
			nNum |= 1<<nLoop;
	}
	return nNum;
}

int main()
{
	int nSum = GetNum();

	if(nSum==0 || nSum==65535)
	{
		cout<<"0"<<endl;
		return 0;
	}
	parent[nSum] = -1;

	int nBfs = bfs(nSum);
	if(nBfs != -1)
		cout<<GetDepth(nBfs)<<endl;
	else
		cout<<"Impossible"<<endl;
	return 0;
}
