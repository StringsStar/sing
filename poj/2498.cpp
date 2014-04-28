#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int Factor[3] = {9,3,7};
int Nums[10] = {0};

int main()
{
	int nSeqs,nLoop=0;
	string str;
	cin>>nSeqs;
	while(nSeqs--) {
		nLoop++;
		cin>>str;
		int nMarks=-1;
		int nLen=str.length();
		for(int i=0;i<str.length();i++) {
			char c=str.at(i);
			if(c=='?')
			{ nMarks=i+1; Nums[i+1]=0; continue; }
			else
			{ Nums[i+1]=c-'0'; continue; }
		}
		//let's calculate
		int nSum=0;
		for(int i=nLen;i>=1;i--) {
			int nFac = (nLen-i) % 3;
		  nSum += Factor[nFac] * Nums[i];	
		}
		//calculate nMarks
		int nFac = (nLen-nMarks)%3;
		for(int i=0;i<=9;i++)
		{
			if( (nSum+Factor[nFac]*i)%10 == 0)	
			{ Nums[nMarks]=i; break;}
		}
		//let's output
		printf("Scenario #%d:\n",nLoop);
		for(int i=1;i<=nLen;i++) {
			printf("%d",Nums[i]);	
		}
		printf("\n\n");
	}
}
