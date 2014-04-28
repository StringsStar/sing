#include <iostream> 
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
	int pX;
	int pY;
};
Point MainDatas[1000];
bool bBadPoint=false;
int nSets,nRad;

bool operator < (const Point &a , const Point& b)
{
	return a.pX < b.pX;	
}

bool operator == (const Point& a , const Point& b)
{
	return ((a.pX==b.pX)&&(a.pY==b.pY));
}

void PrintAll()
{
	for(int i=0 ; i<nSets; i++)	
	{
		cout<<MainDatas[i].pX<<" : "<<MainDatas[i].pY<<endl;	
	}
}
void InitDatas(int nNumberOfSet)
{
	bBadPoint = false;
	for (int i= 0;  i< nNumberOfSet; i++)
	{
		cin>>MainDatas[i].pX>>MainDatas[i].pY;
		//可能会有溢出的问题，草
		if(abs(MainDatas[i].pY) > nRad) {
				bBadPoint = true;
			}
	}
	std::sort(MainDatas , MainDatas+nNumberOfSet);
}


double GetEdge(Point& a)
{
	return double(a.pX) + sqrt(double(nRad*nRad) - a.pY*a.pY);
}
int CalcNumbers()
{
	int nNumbers = 1;
	double dX = GetEdge(MainDatas[0]);
	for(int i=1 ; i < nSets ; i++)
	{
		double dTemp = GetEdge(MainDatas[i]);
		if(dTemp<=dX && MainDatas[i].pX<=dX) {
			dX = dTemp;
			continue;
		}
		if(dTemp>dX && MainDatas[i].pX<=dX)
			continue;
		//Right
		if(MainDatas[i].pX>dX && ((MainDatas[i].pX-dX)*(MainDatas[i].pX-dX)+MainDatas[i].pY*\
				MainDatas[i].pY) <=nRad*nRad )
			continue;
		
		nNumbers++;
		dX = dTemp;
	}
	return nNumbers;
}

int main()
{
	int nLoop=0;
	cin>>nSets>>nRad;
	while(nSets!=0 || nRad!=0) {
		nLoop++;
		InitDatas(nSets);			
		if(bBadPoint==true) {
			printf("Case %d: -1\n", nLoop);
			cin>>nSets>>nRad;
			continue;
		}
		printf("Case %d: %d\n",nLoop , CalcNumbers() );
		cin>>nSets>>nRad;
	}

	return 0;
}

