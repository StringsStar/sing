#include <iostream> 
#include <cstdio>
#include <string.h>
using namespace std;

int N[60001];
int Flag[60001];
int visit[6];
int nSum;

void PutOk()
{
	printf("Can be divided.\n\n");	
}

void PutError()
{
	printf("Can't be divided.\n\n");
}

int DP()
{
	int nWant = nSum/2;
	memset(N , 0 , 60001*sizeof(int) );
	memset(Flag,0,60001*sizeof(int) );
	N[0]=0;
	Flag[0]=1;
	int max=0;
	for(int i=0;i<6;i++)
	{
		int nValue=i+1;
		if(visit[i]==0)
			continue;
		for(int k=max; k>=0 ; k--)
		{
			for(int j=1;j<=visit[i];j++)
			{
				int nCur=N[k]+j*nValue;	
				if(nCur==nWant) 					
					return 0;
				else if(nCur > nWant)
					continue;
				else {	
					if(Flag[nCur] == 0)	
						{ N[++max]=nCur;Flag[nCur]=1; }
				}
			}
		}
	}
	/*code here*/	
	return 1;
}

int main()
{
	int nLoop=0;
	while(1) {
		nLoop++;
		nSum=0;
		for(int i=0;i<6;i++) {
			cin>>visit[i];
			nSum += (i+1)*visit[i];
		}
		if(nSum==0)
			break;

		printf("Collection #%d:\n",nLoop);
		if(nSum%2==1)	{
			PutError();
			continue;
		}

		if(DP() == 0)
			PutOk();
		else
			PutError();
	}
}
