#include <iostream> 
#include <cstdio>
#include <cmath>
using namespace std;

void Calc(int nNum,int* Data,int& nLen)
{
	if(nNum==0) {
		Data[0] = 0;
		nLen = 0;
		return;
	}

	int nLoop=0;
	while(nNum!=0)
	{
		Data[nLoop] = nNum%10;
		nNum = nNum/10;
		nLoop++;
	}
	nLen = nLoop; //update nlen
}
int main()
{
	int n1,n2;
	while(cin>>n1>>n2 && (n1!=0 || n2!=0) )
	{
		int Data1[10]={0};
		int Data2[10]={0};
		int nlen1,nlen2;
		Calc(n1,Data1,nlen1);
		Calc(n2,Data2,nlen2);
		int nTop = max(nlen1 , nlen2);
		int nCarry=0;
		int nCurCarry=-1;
		for(int i=0;i<nTop;i++)
		{
			int nB=0;
			if(nCurCarry==i)
				nB=1;			
			if((nB+Data1[i]+Data2[i])>=10) {
				nCurCarry=i+1;	
				nCarry++;
			}
		}
		//let's output
		if(nCarry==0) {
			printf("No carry operation.\n");
			continue;
		} else if(nCarry==1) {
			printf("1 carry operation.\n");	
			continue;
		} else {
			printf("%d carry operations.\n",nCarry);	
			continue;
		}
	}
}
