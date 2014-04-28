#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int Count[13];
int main()
{
	int nSequence;
	while(cin>>nSequence && nSequence!=0)
	{
		string str;
		int nMost=0;
		std::getline(cin,str);
		for(int i=0; i<nSequence;i++) {
			std::getline(cin , str);
			int nNum=0;
			for(int j=0 ;j<25;j++) {
				if(str.at(j)=='X')
					nNum++;
			}
			Count[i] = nNum;
			nMost = nNum > nMost ? nNum : nMost;
			//let's output
		}
		//let's output
		int nPut=0;
		for(int i=0 ; i<nSequence;i++) {
			nPut += (nMost-Count[i]);	
		}
		printf("%d\n",nPut);
	}
}
