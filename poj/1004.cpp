#include <iostream>
using namespace std;

int main()
{
	int nLoop=12;
	float fCur,fSum=0;
	while(nLoop--)
	{
		cin>>fCur;	
		fSum += fCur;
	};

	cout<<"$"<<fSum/12<<endl;
	return 0;	
}
