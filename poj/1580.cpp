#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string sF;
	string sB;
	while(cin>>sF && sF!="-1")
	{
		cin>>sB;
		int nF = sF.length();
		int nB = sB.length();
		int nMax=0;
		int nSum=0;
		int i=0;
		for(int j=nB-1;j>=1-nF;j--) {
			nSum=0;
			for(int ki=i,kj=j;ki<nF && kj<nB;ki++,kj++)
			{
				if(kj < 0)
					continue;

				if(sF.at(ki) == sB.at(kj) )
				{
					nSum++;	
				}
			}
			nMax = nSum > nMax ? nSum : nMax;
		}
		//Get The Minimal Number
		int nTop=nMax*2 , nBottom=nF+nB;
		if(nTop%nBottom == 0) {
			printf("appx(%s,%s) = %d\n",sF.c_str(),sB.c_str(),nTop/nBottom);
			continue;
		} else {
			for(int i=2;i<=nTop;i++) {
				while(nTop%i==0 && nBottom%i==0) {
					nTop = nTop/i;
					nBottom = nBottom/i;
				}	
			}	
			printf("appx(%s,%s) = %d/%d\n",sF.c_str(),sB.c_str(),nTop,nBottom);
		}
	} //end of while
	return 0;
}
