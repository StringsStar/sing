#include <iostream> 
#include <cstdio> 
#include <cmath>
using namespace std;

#define PI 3.1415926

int main()
{
	int nPoints;
	double nRadius;
	while(cin>>nPoints)
	{
	cin>>nRadius;
	double faX,faY;
	double dTempX,dTempY;
	cin>>faX>>faY;
	dTempX = faX;
	dTempY = faY;
	double dRope=0;
	double d1,d2;
	for(int i=1;i<nPoints;i++)
	{
		cin>>d1>>d2;
		double dLen=sqrt(pow(d1-dTempX,2)+\
				pow(d2-dTempY,2) );
		dRope += dLen;
		dTempX = d1;
		dTempY = d2;
	}
  //last d1 d2
  double dFinal = sqrt(pow(d1-faX,2)+\
			pow(d2-faY,2));
	dRope += dFinal;

	//Radius
	double dRadius = 2*PI*nRadius;
	dRope += dRadius;
	printf("%.2lf\n",dRope);
	}
	return 0;
}
