#include <iostream>
using namespace std;

struct Point {
	int nX;
	int nY;
};

Point P[200];
int main()
{
	int nSets;	
	cin>>nSets;
	int nLoop=0;

	while(nSets--)
	{
		cin>>P[nLoop].nX;
		cin>>P[nLoop].nY;
		nLoop++;
	}
	//let's calculate
	int nMax=0;
	for(int i=0;i<nLoop;i++)
	{
		for(int j=i+1;j<nLoop;j++) {
			int nSum=0;
			Point p;
			p.nX = P[j].nX-P[i].nX;
			p.nY = P[j].nY-P[i].nY;
			for(int k=j+1;k<nLoop;k++) {
				if((P[k].nX-P[i].nX)*p.nY == \
					(P[k].nY-P[i].nY)*p.nX ) {
						nSum++;	
					}
			}
		  nMax = max(nMax , nSum);
		}
	}
	cout<<nMax+2<<endl;
}
