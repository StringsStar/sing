#include <iostream> 
#include <cstdio> 
int Region[260][260];

using namespace std;

int main()
{
	int N,B,K;
	cin>>N>>B>>K;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin>>Region[i][j];

	//start Query
	for(int i=0;i<K;i++)
	{
		int nRow,nCol;
		cin>>nRow>>nCol;
		int nMax=Region[nRow][nCol];
		int nMin=nMax;
		for(int i=nRow;i<nRow+B;i++)
			for(int j=nCol;j<nCol+B;j++)
			{
				if(Region[i][j] > nMax) {
					nMax = Region[i][j];	
					continue;
				} else if(Region[i][j] < nMin) {
					nMin = Region[i][j];
					continue;
				}
			}
		cout<<(nMax-nMin)<<endl;
	}
}
