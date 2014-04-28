#include <iostream> 
#include <cstdio> 
using namespace std;

int main()
{
	int nSets;
	cin>>nSets;
	while(nSets--)
	{
		int nSum,nSub;
		cin>>nSum>>nSub;
		if(nSum%2==1 && nSub%2==0) {
			printf("impossible\n");
			continue;
		}
		else if(nSum%2==0 && nSub%2==1) {
			printf("impossible\n");
			continue;
		}
		int nTop = (nSum+nSub)/2;
		int nBottom = (nSum-nSub)/2;
		if(nBottom<0) {
			printf("impossible\n");
			continue;
		} else {
			printf("%d %d\n",nTop,nBottom);
			continue;
		}
	}
}
