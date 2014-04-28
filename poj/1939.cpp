#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int nSeqs;
	while(cin>>nSeqs)
	{
		double dX,dY,dX0,dY0,dxT,dyT;
		cin>>dX0>>dY0;
		dxT=dX0;
		dyT=dY0;

		cout<<nSeqs;
		for(int i=2;i<=nSeqs;i++) {
			cin>>dX>>dY;
			double dXL=(dX+dxT)/2.0;
			double dYL=(dY+dyT)/2.0;
			dxT = dX;
			dyT = dY;
			printf(" %0.6f %0.6f",dXL,dYL);
		}
		dX = (dX+dX0)/2.0;
		dY = (dY+dY0)/2.0;
		printf(" %0.6f %0.6f\n",dX,dY);
	}
}
