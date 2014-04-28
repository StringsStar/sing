#include <iostream> 
#include <cstdio> 
#include <cmath>
using namespace std;

int D[100]={0};
int main()
{
	int nSons;
	int nBys;
	cin>>nSons>>nBys;
	int nTemp=0;
	for(int i=0;i<nSons;i++) {
		cin>>D[i];
		if(nBys % 2 == 1) {
			if(D[i]>0) nTemp = nTemp + pow(D[i],nBys);	
		} else {
			nTemp = nTemp + pow(D[i],nBys);	
		}
	}

	cout<<nTemp<<endl;
	return 0;
}
