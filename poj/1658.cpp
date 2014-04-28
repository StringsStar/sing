#include <iostream> 
#include <cstdio> 
using namespace std;

int main() {
	int nSets;
	cin>>nSets;
	while(nSets--) {
		bool bSum=true;
		int nInterval;
		int nMulti;
		int mNumbers[5];
		int mInterval[4];
		for(int i=0;i<4;i++)
		{
			cin>>mNumbers[i];
		}

		for(int i=1;i<4;i++) {
			mInterval[i]=mNumbers[i]-mNumbers[i-1];	
			if(i==1)
				nInterval=mInterval[i];
			else {
				if(mInterval[i] != nInterval) {bSum=false; break;}	
			}
		}
		if(bSum==true) {
			mNumbers[4] = mNumbers[3] + nInterval;	
		} else {
			nMulti = mNumbers[1]/mNumbers[0];
			mNumbers[4] = mNumbers[3]*nMulti;
		}
	
		//let's output
		printf("%d %d %d %d %d\n",mNumbers[0],mNumbers[1],\
				mNumbers[2],mNumbers[3],mNumbers[4]);
	}
}
