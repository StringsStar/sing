#include <iostream> 
#include <cstdio>
#include <string.h>
using namespace std;

int Num[6] = {0};
int visit[6] = {0};
int nvisit=0;
int nWant=0;
int nValue=0;

void PutOk()
{
	printf("Can be divided.\n\n");	
}

void PutErr()
{
	printf("Can't be divided.\n\n");	
}

void PrintVisit()
{
	for(int i=0;i<6;i++)
	{
		cout<<visit[i]<<" ";	
	}
	cout<<endl;
	cout<<nValue<<" "<<nvisit<<endl;
}
int findW()
{
	for(int i=0;i<6;i++)
	{
		if(visit[i]<Num[i] && i >= nvisit) {
			int nTemp=nvisit;
			visit[i]++;	
			nvisit=i;
			nValue += (i+1);
			PrintVisit();
			if(nValue == nWant) {
				return 0;
			}
			else if(nValue < nWant) {
				if(findW()==0) return 0;
				nvisit=nTemp;
				visit[i]--;
				nValue -= (i+1);
				continue;
			} else {
				visit[i]--;
				nValue -= (i+1);
				nvisit=nTemp;
				return 1;
			}
		}
	}
	return 1;
}

int main() {
	int nLoop=0;
	while(1)
	{
		nLoop++;
		int nSum=0;
		for(int i=0;i<6;i++) {
			cin>>Num[i];
			nSum += (i+1)*Num[i];
		}
		if(nSum==0)	
			break;

		printf("Collection #%d:\n",nLoop);	
		if(nSum%2 == 1) {
			PutErr();
			continue;
		}
		nWant = nSum/2;
		memset(visit,0,sizeof(int) );
		nvisit=0;
		nValue=0;
		if(findW() == 0)
			PutOk();
		else
			PutErr();
	}
}
