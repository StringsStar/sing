#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int nSets;
	int nRow,nCol;	
	cin>>nSets;
	int nLoop=0;

	while(nSets--)
	{
		nLoop++;
		cin>>nRow>>nCol;
		printf("Scenario #%d:\n",nLoop);	
		if( (nRow%2)== 1 && \
				(nCol%2)==1) {
			float f = (nRow)*(nCol)+0.41;
					printf("%0.2f\n\n",f);	
		} else {
			float f = nRow*nCol;
			printf("%0.2f\n\n",f);
		}
	}
}
