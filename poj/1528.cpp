#include <iostream> 
#include <cstdio> 
using namespace std;

int main() {
	int nInput;
	printf("PERFECTION OUTPUT\n");
	while(cin>>nInput && nInput!=0)
	{
		int nSum=0;
		for(int i=1;i<nInput;i++) {
			if(nInput%i == 0)	
				nSum+=i;
		}
		if(nSum==nInput) {
			printf("%5d  PERFECT\n",nInput);	
		} else if(nSum<nInput) {
			printf("%5d  DEFICIENT\n",nInput);	
		} else {
			printf("%5d  ABUNDANT\n",nInput);	
		}
	}
	printf("END OF OUTPUT\n");
}
