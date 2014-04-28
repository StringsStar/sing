#include <iostream>
#include <string.h>
using namespace std;

int GetCycle(int nInput)
{
	int nLoop=0;
	while(nInput != 1)
	{
		if(nInput%2 == 0)	{
			nInput = nInput/2;
			nLoop++;
		}
		else {
			nInput = 3*nInput+1;
			nLoop++;
		}
	}
	nLoop++;
	return nLoop;
}
int main()
{
	int nT,nB;
	while(cin>>nB>>nT)
	{
		int nBottom,nTop;
		nBottom = (nB > nT) ? nT : nB;
		nTop = (nB <= nT) ? nT : nB;
		int nSum=0;
		int nIndex=-1;
		for(int i=nBottom;i<=nTop;i++)
		{
			int n = GetCycle(i);
			if(n>nSum) {
				nSum = n;	
				nIndex = i;
			}
		}
		cout<<nB<<" "<<nT<<" "<<nSum<<endl;
	}
}
