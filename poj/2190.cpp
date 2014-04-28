#include <iostream>
#include <cstdio>
using namespace std;

int D[10];

int main()
{
	char c;
	int nMarks;
	for(int i=0;i<10;i++)	
	{
		cin>>c;
		if(c=='?') {
			nMarks = i;
			continue;
		}
		if(c!='X')
			D[i] = c-'0';
		else
			D[i] = 10;
	}

	int nTemp=0;
	for(int i=0;i<10;i++) {
		if(i==nMarks)
			continue;
		int nMulti = 10-i;
		nTemp += D[i]*nMulti;
	}

	int nBys = 10-nMarks;
	int i;
	for(i=0;i<=10;i++)
	{
		int N = nTemp+i*(nBys);
		if(N % 11 == 0)
			break;
	}
	if(nMarks==9 && i==10)
		cout<<"X"<<endl;
	else if(nMarks==9)
		cout<<i<<endl;
	else if(nMarks<9 && i<10)
		cout<<i<<endl;
	else
		cout<<"-1"<<endl;
}
