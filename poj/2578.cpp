#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int nTemp;
	for(int i=0;i<3;i++)
	{
		cin>>nTemp;
		if(nTemp<168)
			break;
	}
	if(nTemp<168)
		printf("CRASH %d\n",nTemp);
	else
		printf("NO CRASH\n");
}
