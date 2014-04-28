#include <iostream> 
#include <string> 
#include <cstdio> 
#include <algorithm>
using namespace std;

int GetReverseNumber(string strInput)
{
	std::reverse(strInput.begin() , strInput.end() );	
	int Nlen = strInput.length();
	int nTemp=0;
	for(int i=0 ; i< Nlen ; i++) {
		int n = strInput.at(i)-'0';	
		nTemp = nTemp*10 + n;
	}
	return nTemp;
}

int main()
{
	int nS;
	cin>>nS;
	string strNum;
	char szText[100];
	while(nS--)
	{
		cin>>strNum;
		int nF = GetReverseNumber(strNum);
		cin>>strNum;
		int nL = GetReverseNumber(strNum);
		int n = nF + nL;
		sprintf(szText , "%d" , n);
		strNum = szText;
		cout<<GetReverseNumber(strNum)<<endl;
	}
	return 0;
}
