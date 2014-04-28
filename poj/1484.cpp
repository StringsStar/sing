#include <iostream> 
#include <cstdio> 

using namespace std;

int main()
{
	int nSets,nOperations,nCapcity,nLoop=0;	
	while(cin>>nSets>>nOperations>>nCapcity)
	{
		if(nSets==0 && nOperations==0 && nCapcity==0)	
			break;

		nLoop++;
		int nTurnOn[20] = {0};
		int m_nCapcity[20] = {0};
		int nTop=0,nCurOp,nCurAsper=0;
		for(int i=0;i<nSets;i++) {
			cin>>m_nCapcity[i];
		}
		for(int j=0;j<nOperations;j++) {
			cin>>nCurOp;
			if(nTurnOn[nCurOp-1] == 0) {
				nTurnOn[nCurOp-1] = 1;
				nCurAsper += m_nCapcity[nCurOp-1];
				nTop = (nCurAsper > nTop) ? nCurAsper : nTop;
			} else {
				nTurnOn[nCurOp-1] = 0;
				nCurAsper -= m_nCapcity[nCurOp-1];
			}
		}

		//let's output
		printf("Sequence %d\n",nLoop);
		if(nTop > nCapcity) {
			printf("Fuse was blown.\n\n");	
		} else {
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n\n",nTop);
		}
	}
}
