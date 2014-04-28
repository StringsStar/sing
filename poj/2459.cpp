#include <iostream>

using namespace std;

struct Eat {
	int nLeft;
	int nRight;
};

Eat Cows[100];
int main()
{
	int C,F1,F2,D;
	cin>>C>>F1>>F2>>D;

	for(int i=0;i<C;i++)
	{ cin>>Cows[i].nLeft;cin>>Cows[i].nRight; }

	int nConsum=F1-F2;
	int nTemp=0;
	int i;
	for(i=D;i>=0;i--)
	{
		int nCount=0;
		for(int j=0;j<C;j++)	
			if(i>=Cows[j].nLeft && i<=Cows[j].nRight)
				nCount++;

		nTemp+=nCount;
		if(nTemp==nConsum)
			break;
	}
	cout<<i<<endl;
	return 0;
}
