#include <iostream> 
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;

int N[5845];
string GetSt(int nSeq)
{
	int n1 = nSeq%10;
	int n2 = nSeq%100;
	if(n1>0 && n1<=3 && (n2<10 || n2>13))
	{
		if(n1 == 1)
			return "st";
		else if(n1 == 2)
			return "nd";
		else if(n1 == 3)
			return "rd";
	} else 
		return "th";
}

int main()
{
	N[1] = 1;
	int N2=1;
	int N3=1;
	int N5=1;
	int N7=1;
	for(int i=2;i<=5842;i++)
	{
		int nMin=	min(N[N2]*2,min(N[N3]*3,min(N[N5]*5,N[N7]*7)) );
		N[i] = nMin;
		if(nMin == N[N2]*2)
			N2++;
		if(nMin == N[N3]*3)
			N3++;
		if(nMin == N[N5]*5)
			N5++;
		if(nMin == N[N7]*7)
			N7++;
	}
	int nSeq;
	while(cin>>nSeq && nSeq!=0)
	{
		printf("The %d%s humble number is %d.\n",nSeq,GetSt(nSeq).c_str(),N[nSeq]);
	}
}
