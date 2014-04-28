#include <iostream> 
#include <cstdio>
using namespace std;

int Bricks[100];
int main()
{
	int nSets;
	int nLoop=0;
	while(cin>>nSets && nSets!=0)
	{
		nLoop++;
		int nSum=0;
		for(int i=0 ; i<nSets;i++) {
			cin>>Bricks[i];
			nSum += Bricks[i];
		}

		int nAver = nSum/nSets;
		int nCount=0;
		for(int i=0;i<nSets; i++) {
			if(Bricks[i] > nAver)	{
				nCount+=(Bricks[i]-nAver);	
			}
		}
		printf("Set #%d\n",nLoop);	
		printf("The minimum number of moves is %d.\n\n",nCount);
	}
}
