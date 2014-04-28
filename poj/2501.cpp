#include <iostream>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <string.h>
using namespace std;

int Seconds(int nHour,int nMinute,int nSecond)
{
	return (3600*nHour+60*nMinute+nSecond);	
}
int main()
{
	int nSeconds=0,nSpeed=0;
	float fDistance=0;
	char ss[100];
	while(cin.getline(ss,100) )
	{
		int nLen = strlen(ss);
		if(nLen==0)
			break;

		if(nLen > 9) { //变速
			int nHour,nMin,nSec,nCurSpeed;
			sscanf(ss,"%02d:%02d:%02d %d",&nHour,&nMin,&nSec,&nCurSpeed);
			float fPass=(Seconds(nHour,nMin,nSec)-nSeconds)*nSpeed/3600.0;
			float fAll=fDistance+fPass;
			fDistance=fAll; //update fDistance
			nSpeed = nCurSpeed; //update fDistance
			nSeconds = Seconds(nHour,nMin,nSec); //update nSeconds;
		} else { //Query
			int nHour,nMin,nSec;
			sscanf(ss,"%02d:%02d:%02d",&nHour,&nMin,&nSec);
			float fPass=(Seconds(nHour,nMin,nSec)-nSeconds)*nSpeed/3600.0;
			float fAll=fDistance+fPass;
			printf("%s %0.2f km\n",ss,fAll);
		}
	}
}
