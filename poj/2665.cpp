#include <iostream> 
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	int nLong,nSets;
	while(cin>>nLong>>nSets&&\
			(nLong!=0 || nSets!=0) )
	{
		int M[5005] = {-1};
		memset(M,-1,5005*sizeof(int) );
		int nLen=0;
		int nSum=0;
		int nP=0;
		for(int i=0;i<nSets;i++) {
			//InsertDot
			int nStart,nEnd;
			cin>>nStart>>nEnd;
			nSum+=(nEnd-nStart)+1;
		}
		cout<<nLong+1-nSum<<endl;
	}
}
