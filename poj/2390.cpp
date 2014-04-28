#include <iostream>
#include <cmath> 
#include <cstdio>
using namespace std;

int main()
{
	int nRate,nMon,nYear;
	cin>>nRate>>nMon>>nYear;
	double dRate = 1.0+nRate/100.0;
	double dAll = pow(dRate , nYear);
	double dMon = nMon*dAll;
	printf("%d\n",(int)dMon);
}
