#include <iostream> 
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int nNum;
int Digits[5];
int nDigit;
string str;

void CinToDigits(int nInput)
{
	int nTemp = nInput;
	int nLoop=0;
	for(int i=0; i<4 && nTemp!=0 ; i++)
	{
		Digits[i] = nTemp % 10;
		nTemp = nTemp / 10;
		nLoop++;
	}
	sort(Digits , Digits+nLoop);
	nDigit = nLoop;
}
int GetMinNum() {
	int nTemp=0;
	for(int i=0 ; i < nDigit;i++)
		nTemp = nTemp*10 + Digits[i];
	return nTemp;
}

int GetLargeNum() {
	int nTemp = 0;
	for(int i=nDigit-1 ; i>=0 ; i--)
		nTemp = nTemp*10 + Digits[i];
	return nTemp;
}
void ShowAllCycles()
{
	int nLoop=0;
	printf("N=%s:\n",str.c_str() );
	while(1) {
		nLoop++;

		int nLarge = GetLargeNum();
		int nMin = GetMinNum();
		int nX = nLarge-nMin;
		printf("%d-%d=%d\n",nLarge,nMin,nX );
		if(nX==0 || nX==6174)
			break;
		else
			CinToDigits(nX);
	}
	printf("Ok!! %d times\n",nLoop);
}

int main()
{
	while(cin>>str && str!="-1")
	{
		//Manual Input
		if(str.length() != 4) {
			cout<<"N="<<str<<":"<<endl;
			cout<<"No!!"<<endl;
			continue;
		}
		for(int i=0 ; i< str.length() ; i++) {
			Digits[i] = str.at(i)-'0';	
		}
		nDigit = 4;
		std::sort(Digits,Digits+4);

		if(Digits[0]==Digits[1] && \
				Digits[1]==Digits[2] &&\
				Digits[2]==Digits[3]) {
			cout<<"N="<<str<<":"<<endl;
			cout<<"No!!"<<endl;
		} else {
			ShowAllCycles();	
		}
		/*code here*/	
	}
	return 0;
}
