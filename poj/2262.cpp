#include <iostream> 
#include <cstdio>
#include <cmath>
using namespace std;

void PutErr()
{
	printf("Goldbach's conjecture is wrong.\n");
}

int IsPrime(int N)
{
	int nSqrt = sqrt(N);
	int n=0;
	for(int i=2;i<=nSqrt;i++)
	{
		if(N%i == 0) {
			n = 1;
			break;
		}
	}
	return n;
}
int main()
{
	int nNum;
	while(cin>>nNum&&nNum!=0)
	{
		int nFlag=1;
		int nVal;
		if(nNum%2 == 1) {
			PutErr();
			continue;
		}
		for(int i=1;i<=nNum/2;i++)
		{
			nVal = i*2+1;	
			if(0==IsPrime(nVal) && 0==IsPrime(nNum-nVal) ) {
				nFlag = 0;
				break;
			}
		}
		if(0==nFlag)
			printf("%d = %d + %d\n",nNum,nVal,(nNum-nVal) );
		else
			PutErr();
	}
}
