/*
	 this program is too doubi

	 *
*/

#include <iostream>
#include <cstdio>

using namespace std;

int N[50001];

int main()
{
	N[1] = 0;
	int nSets;
	cin>>nSets;
	if(nSets < 4) {
		cout<<0<<endl;
		return 0;
	}
	cin>>N[2];
	cin>>N[3];

	int nMin = N[3]-N[2];
	int nCur = 3;
	for(int i=4; i<nSets; i++)
	{
		cin>>N[i];
		if( (N[i]-N[i-1])<nMin) {
			nMin = N[i] - N[i-1];
			nCur = i;
		}
	}
	//Last One
	cin>>N[nSets];
	cout<<N[nSets]+nMin<<endl;
	printf("%d %d %d %d\n",nCur,1,nSets,nCur-1);
	/*code here*/	
}
