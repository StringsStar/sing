#include <iostream>
using namespace std;

int viist[10000]={0};

int GetSelf(int n)
{
	int n1 = n%10;
	int n2 = (n%100-n1)/10;
	int n3 = (n%1000-n2*10-n1)/100;
	int n4 = n/1000;
	return (n+n1+n2+n3+n4);
}
int main()
{
	for(int i=0 ; i < 10000 ; i++)
	{
		int nSub = GetSelf(i);
		while(nSub < 10000)
		{
			if(viist[nSub]==0)	{
				viist[nSub]=1;
				nSub = GetSelf(nSub);
				continue;
			}
			else
				break;
		}
	}

	for(int i=1 ; i < 10000 ;i++)		
	{
		if(viist[i]==0)	
			cout<<i<<endl;
	}
}
