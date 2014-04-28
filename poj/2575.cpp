#include <iostream> 
#include <cstdio>
#include <cmath>
#include <string.h>
using namespace std;

int main()
{
	int nNum;
	int nFlags[3001];
	while(cin>>nNum)
	{
		if(nNum==1) {
			int n;
			cin>>n;
			printf("Jolly\n");
			continue;
		} else {
			memset(nFlags,0,3001*sizeof(int) );
			int nCur;
			bool bflag=true;
			cin>>nCur;
			for(int i=1;i<nNum;i++)
			{
				int nTemp;
				cin>>nTemp;
				int nAbs=abs(nTemp-nCur);
				if(nAbs>3000)
		      bflag = false;
				else {
					nFlags[nAbs] = 1;
				  nCur = nTemp;
				}
			}
			for(int i=1;i<=nNum-1;i++)
			{
				if(nFlags[i] == 0) {
					bflag = false;
					break;
				}	
			}

			if(bflag == true) {
				printf("Jolly\n");
				continue;
			} else {
				printf("Not jolly\n");
				continue;
			}
		}
	}
}
