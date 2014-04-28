#include <iostream> 
#include <cstdio> 

using namespace std;

int main()
{
	int P[5];
	int nSets;
	cin>>nSets;
	while(nSets--)
	{
		for(int i=0;i<4;i++)	
		{
			int nTemp=0;
			for(int j=0;j<8;j++)	
			{
				char c;
				cin>>c;
				int n = c-'0';
				nTemp = nTemp*2 + n;
			}
			P[i] = nTemp;
		}

		printf("%d.%d.%d.%d\n",P[0],P[1],P[2],P[3]);
	}
	return 0;
}
