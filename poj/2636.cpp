#include <iostream>
using namespace std;

int main()
{
	int nSeqs;
	cin>>nSeqs;
	while(nSeqs--)
	{
		int nStrips;
		cin>>nStrips;
		int nSum=0,nTemp;
		for(int i=0;i<nStrips;i++) {
			cin>>nTemp;
			nSum+=nTemp;
		}
		cout<<nSum-nStrips+1<<endl;
	}
}
