#include <iostream>
using namespace std;

const float PI = 3.1415926;
int main()
{
	int nSets;
	float fX,fY;
	cin>>nSets;
	int nLoop=0;	
	while(nSets--)
	{
		cin>>fX>>fY;
		float fSquare = 0.5*PI*(fX*fX + fY*fY);
		
		nLoop ++;
		int nYear = fSquare/50 + 1;
		cout<<"Property "<<nLoop<<": "<<\
		"This property will begin eroding in year "<<nYear<<"."<<endl;
	}
	cout<<"END OF OUTPUT."<<endl;
	return 0;
}
