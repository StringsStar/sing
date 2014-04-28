#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int nNum;
	while(cin>>nNum)
	{
		int tmp=1;
		int nLoop=1;
		if(nNum==1) {
			printf("1\n");
			continue;
		}

		while(tmp) //0退出 1继续
		{
			tmp=tmp*10+1;
			nLoop++;
			tmp = tmp%nNum;
		}
		printf("%d\n",nLoop);
	}

}
