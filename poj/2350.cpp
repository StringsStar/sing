#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int nSets;
	cin>>nSets;
	while(nSets--)
	{
		int nSeq;
		cin>>nSeq;
		int N[1000] = {0};
		int nSum=0;
		for(int i=0;i<nSeq;i++)
		{
			cin>>N[i];
			nSum += N[i];
		}
		float f = nSum/nSeq;

		int nCount=0;
		for(int i=0;i<nSeq;i++)
		{
			if(N[i] > f)
				nCount++;
		}
		double d = (100.0*nCount)/nSeq;
		printf("%0.3f%%\n",d);
	}
}
