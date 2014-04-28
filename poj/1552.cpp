#include <iostream> 
#include <cstdio> 
#include <algorithm>
using namespace std;

int main() {
	/*code here*/	
	int nFirst;
	while(cin>>nFirst && nFirst!=-1)
	{
		if(nFirst == 0) {
			cout<<0<<endl;
			continue;
		}

		int nVisit[100] = {0};	
		int nDatas[100];
		nVisit[nFirst] = 1;
		nDatas[0] = nFirst;
		int nTemp;
		int nLoop=1;
		while(cin>>nTemp && nTemp!=0) {
			nVisit[nTemp] = 1;	
			nLoop++;
			nDatas[nLoop-1] = nTemp;
		}
		std::sort(nDatas , nDatas+nLoop);
		int nCount=0;
		for(int i=0 ;i<nLoop;i++) {
			if(nDatas[i]*2 > nDatas[nLoop-1])
				continue;
			if(nVisit[nDatas[i]*2] == 1)
				nCount++;
		}
		cout<<nCount<<endl;
	}
}
