#include <iostream> 
#include <cmath>
using namespace std;

#define NUM 10000000
int D[NUM+2];

int main()
{
 	D[1] = 1;
	int N1=1;
	int N2=1;
	int nTemp=1;
	while(nTemp<NUM)
	{
		int nCur = nTemp+1;
		D[nCur] = min(D[N1]*2+1,D[N2]*3+1);
	  if(D[nCur]==(D[N1]*2+1) )	
			N1++;
		if(D[nCur]==(D[N2]*3+1) )
			N2++;
		nTemp++;

		if(nTemp>NUM)
			break;
	}

	int nNum;
	while(cin>>nNum)
		cout<<D[nNum]<<endl;
}
