#include <iostream> 
#include <string.h> 
using namespace std;

int m_Guests[30];
int nGuests;

int FindSamPos()
{
	int SumSam=0,SumElla=0;
	int PosSam=1,PosElla=nGuests;
	SumSam = m_Guests[PosSam-1];
	SumElla = m_Guests[PosElla-1];

	while(PosSam < PosElla-1)
	{
		if(SumSam < SumElla) {
			PosSam++;
			SumSam += m_Guests[PosSam-1];
		}
		else if(SumSam >= SumElla) {
			PosElla--;
			SumElla += m_Guests[PosElla-1];
		}
	}
	if(SumSam == SumElla)
		return PosSam;
	else
		return 0;
}

int main()
{
	while(cin>>nGuests && nGuests!=0)
	{
		for(int i=0 ; i<nGuests; i++)	
			cin>>m_Guests[i];
		int nSam = FindSamPos();
		if(nSam== 0)
			cout<<"No equal partitioning."<<endl;
		else
			cout<<"Sam stops at position "<<nSam<<" and Ella stops at position "\
				<<(nSam+1)<<"."<<endl;
	}
	return 0;	
}
