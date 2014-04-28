#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int nSets;
	cin>>nSets;
	while(nSets--)
	{
		int nEat,nMax;
		cin>>nEat>>nMax;
		if(nEat>=nMax)
			cout<<"MMM BRAINS"<<endl;
		else
			cout<<"NO BRAINS"<<endl;
	}
}
