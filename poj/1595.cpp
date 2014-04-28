#include <iostream> 
#include <cmath> 
#include <cstdio> 
using namespace std;

int nPrime[500];
int nCur=0;
void GenPrimes()
{
	nCur = 0;
	nPrime[nCur] = 1;
	for(int i=2; i<=1000 ; i++)	{
		bool bFlag=true;
		for(int j=2; j<i;j++) {
			if(i % j == 0) {
				bFlag=false;
				break;
			}
		}	
		if(bFlag==true) {
			nCur++;
			nPrime[nCur] = i;
		}
	}
}
int main()
{
	GenPrimes();
	int nNum , nCount;
	while(cin>>nNum>>nCount) {
		int i;
		for(i=0; i<nCur+1;i++)	
			if(nPrime[i]>nNum)
				break;
		int nTop = i-1;
		int nLeft,nRight;
		if((i-1)%2 == 0) {
			nLeft=(i-1)/2; nRight=(i-1)/2;	
		} else {
			nLeft=(i-2)/2; nRight=(i)/2;
		}
		nLeft-=nCount-1;
		nRight+=nCount-1;
		cout<<nNum<<" "<<nCount<<":";
		for(int i=nLeft; i<=nRight ; i++) {
			if(i<0)	
				continue;
			if(i>nTop)
				continue;
			cout<<" "<<nPrime[i];
		}
		cout<<endl<<endl;
	}
	return 0;
		
}
