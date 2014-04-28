#include <iostream> 
#include <cstdio> 
using namespace std;

int main()
{
	int N,Q;
	while(cin>>N>>Q && (N!=0||Q!=0))
	{
		int visit[101]={0};	
		int nMax=0,nDstDate=-1;
		for(int i=0;i<N;i++)
		{
			int nSigma;
			int Date;
			cin>>nSigma;
			for(int j=0;j<nSigma;j++)
			{
				cin>>Date;
				visit[Date]++;

				if(visit[Date] >= Q)
				{
					if(visit[Date] > nMax) {
						nDstDate=Date;
						nMax = visit[Date];
						continue; //Da Jiang You
					} else if(visit[Date] == nMax) {
						if(Date<nDstDate)
							nDstDate=Date;
					}
				}
			}
		}
		if(nDstDate==-1)
			cout<<"0"<<endl;
		else
			cout<<nDstDate<<endl;
	}
	return 0;
}
