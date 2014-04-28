#include <iostream>
#include <cstdio>
using namespace std;
//compile in g++ not c++
int Board[101][101]={0};

int main()
{
	int nSets;
	cin>>nSets;
	while(nSets--)
	{
		int nX,nY,nL;
		string Command;
		cin>>Command>>nX>>nY>>nL;
		if(Command=="BLACK") {
			for(int i=nX;i<=nX+nL-1;i++)
				for(int j=nY;j<=nY+nL-1;j++)
					Board[i][j]=1;
		} else if(Command=="WHITE") {
			for(int i=nX;i<=nX+nL-1;i++)
				for(int j=nY;j<=nY+nL-1;j++)
					Board[i][j]=0;
		} else {
			int nSum=0;
			for(int i=nX;i<=nX+nL-1;i++)
				for(int j=nY;j<=nY+nL-1;j++)
				{
					if(Board[i][j]==1)
						nSum++;
				}
			cout<<nSum<<endl;
		}
	}
}
