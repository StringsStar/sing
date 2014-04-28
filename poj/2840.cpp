#include <iostream> 
#include <cstdio> 
using namespace std;

int main()
{
	int nSeqs;
	cin>>nSeqs;
	char Text[100];
	while(nSeqs--) {
		cin>>Text;
		int nHour,nMin;
		int nClock;
		sscanf(Text,"%02d:%02d",&nHour,&nMin);
		if(nMin!=0) {
			cout<<0<<endl;
			continue;
		} 
		if(nHour<=12) 
			nClock = 12+nHour;
		else
			nClock = nHour-12;
		cout<<nClock<<endl;
	}
}
