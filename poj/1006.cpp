#include <iostream>

using namespace std;

int FetchCurCycle(int nDays , int nDate ,int nCycle)
{
	if(nDate >= nDays)	
		return (nDate-nDays)%nCycle;
	
	if(nDate < nDays)
		return nCycle-(nDays-nDate)%nCycle;
	
}
int main()
{
	int nA,nB,nC,nD;
	int nLoop=0;
	while(cin>>nA>>nB>>nC>>nD)
	{
		if(nA==-1 && nB==-1 && nC==-1 && nD==-1)	
			break;

		bool bJust = (nA>=0 && nA<=365) && \
		(nB>=0 && nB<=365) && \
		(nC>=0 && nC<=365) && \
		(nD>=0 && nD<=365);

		if(!bJust)
			continue;

		nLoop++;
		int nDstDays = (5544*nA + 14421*nB + 1288*nC - nD + 21252) % 21252;
		if(nDstDays == 0)
			nDstDays = 21252;
		cout<<"Case "<<nLoop<<": the next triple peak occurs in "<<nDstDays<<" days."<<endl;
	}
	return 1;
}
