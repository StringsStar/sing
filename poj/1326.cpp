#include <iostream> 
#include <string> 
using namespace std;

int main()
{
	string Src,Dst;
	int nMiles;
	char cCode;
	int nBonus=0;

	while(cin>>Src && Src!="#")
	{
		if(Src=="0")	{
			cout<<nBonus<<endl;
			nBonus = 0;
			continue;
		}		
		cin>>Dst>>nMiles>>cCode;

		int nCalc;
		int nTempMiles;
		if(cCode == 'F') {
			nCalc = 100;
			nTempMiles = nMiles;
		} else if(cCode=='B') {
			nCalc = 50;
			nTempMiles = nMiles;
		} else {
			nCalc = 0;
			if(nMiles<=500)
				nTempMiles = 500;
			else
				nTempMiles = nMiles;
		}

		if( (nTempMiles%2==1) && nCalc==50) {
				nBonus += (nTempMiles+1)*nCalc/100 + nTempMiles;
		} else {
			nBonus += nTempMiles*nCalc/100 + nTempMiles;	
		}
	}
	return 0;
}
