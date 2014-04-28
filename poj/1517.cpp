#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	double f=1;
	int nSum=1;
	for(int i=1;i<=9;i++) {
		nSum = nSum*i;
		double f1 = 1.0/nSum;
		f += f1;
		if(i==1) {
			printf("1 2\n");	
		} else if(i==2) {
			printf("2 2.5\n");	
		} else
		printf("%d %0.9f\n",i , f);
	}

	return 0;
}
