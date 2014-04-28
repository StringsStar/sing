#include <iostream> 
#include <string> 
#include <algorithm>
#include <cmath>
using namespace std;

long long Datas[1600]={1};
int nCur=0;
//Generate 1500 and sort
bool find(int nT,long long nInput)
{
	for(int i=nT ; i<= nCur ; i++) {
		if(Datas[i] == nInput)
			return true;
	}
	return false;
}

int main() {

	int a1=0,a2=0,a3=0;
	for(int i=1; i <= 1500 ; i++)
	{
		Datas[i]=	min(Datas[a1]*2,min(Datas[a2]*3,Datas[a3]*5));
		if(Datas[i]==Datas[a1]*2)
				a1++;
		if(Datas[i]==Datas[a2]*3)
				a2++;
		if(Datas[i]==Datas[a3]*5)
				a3++;
	}
	int nIndex;
	while(cin>>nIndex && nIndex!= 0)
	{
		cout<<Datas[nIndex-1]<<endl;	
	}
}
