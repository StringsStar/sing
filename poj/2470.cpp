#include <iostream> 
#include <cstdio>
using namespace std;

int N[100001];
int Nums[100001];
int main()
{
	int nSeqs;
	while(cin>>nSeqs && nSeqs!=0)
	{
		bool bFlag=true;
	  for(int i=1;i<=nSeqs;i++) {
			scanf("%d" , &Nums[i]);
			N[Nums[i]] = i;
	  }
		for(int i=1;i<=nSeqs;i++) {
			if(Nums[i] != N[i])	
			{ bFlag=false; break; }
		}
		if(bFlag == true)
			printf("ambiguous\n");
		else 
			printf("not ambiguous\n");
	}

}
