#include <iostream> 
#include <cstdio> 
#include <algorithm>
#include <string.h>
using namespace std;

int PNum[110] = {0};
int PG[110] = {0};

int main() {
	int N,P;
	cin>>N>>P;
	for(int i=0;i<N;i++)
	{
		int PCur[110]={0};
		cin>>PCur[1];
		int nTop=PCur[1];
		int nBot=PCur[1];
		for(int j=2;j<=P;j++)
		{
			cin>>PCur[j];
			nTop = PCur[j] > nTop ? PCur[j] : nTop;
			nBot = PCur[j] < nBot ? PCur[j] : nBot;
		}
		for(int i=1;i<=P;i++) {
			if(PCur[i] == nBot)
				PNum[i]++;
			if(PCur[i] == nTop)
				PG[i] = 1;
		}
	}
		//let's output
	bool bFlag=false;
	for(int i=1;i<=P;i++)
	{
		if(PNum[i]>N/2 && PG[i]!=1 &&bFlag==false)	 {
				bFlag = true;	
				printf("%d",i);
		} else if(PNum[i]>N/2 && PG[i]!=1) {
				printf(" %d",i);	
		}
	}
	if(bFlag==false)
		printf("0");
	printf("\n");
}
