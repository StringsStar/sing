#include <iostream> 
#include <cstdio> 
#include <algorithm>
using namespace std;

int Region[900];
int nRow,nCol;
int nWhole;

int main() {
	int nLoop=0;
	while(cin>>nRow>>nCol&&\
			nRow!=0 && nCol!=0)
	{
		nLoop++;
		for(int i=0;i<nRow*nCol;i++)
		{
			cin>>Region[i];	
		}
		cin>>nWhole;
		std::sort(Region,Region+nRow*nCol);
		int nCurH=Region[0];
		int nCurCubes=0;
		int i=1;
		for(i=1;i<nRow*nCol;i++)
		{
			if( (nCurCubes+i*100*(Region[i]-nCurH)) <= nWhole )
			{
				nCurCubes = nCurCubes + i*100*(Region[i]-nCurH);
				nCurH = Region[i];
			} else {
				break;	
			}
		}
		float fH = nCurH + ((float)nWhole-nCurCubes)/(i*100);

		int nCount=0;
		for(int i=0;i<nRow*nCol;i++)
		{
			if(Region[i] < fH) nCount++;
		}
		float fP = (nCount*100.0) / (nRow*nCol);
		printf("Region %d\n",nLoop);
		printf("Water level is %0.2f meters.\n",fH);
		printf("%0.2f percent of the region is under water.\n",fP);
	}
}

