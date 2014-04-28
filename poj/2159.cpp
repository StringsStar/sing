//Fucking Joking Me , Boy
//WTF was thepassword
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

char getChar(char c)
{
	if(c=='Z')
		return 'A';
	else 
		return c+1;
}

int Pass[10] = {2,1,5,4,3,7,6,10,9,8};
int main()
{
	char Chars[100];
	int nInfo[26]={0};
	int nPass[26]={0};
	string strInfo,strPass;
	cin>>strInfo>>strPass;
	int nLen = strInfo.length();
	for(int i=0;i<nLen;i++)
	{
		int N1=strInfo.at(i)-'A';
		int N2=strPass.at(i)-'A';
		nInfo[N1]++;
		nPass[N2]++;
	}

	std::sort(nInfo,nInfo+26);
	std::sort(nPass,nPass+26);
	bool bFlag = true;
	
	for(int i=0;i<26;i++)
	{
		if(nInfo[i]!=nPass[i]) {
			bFlag = false;
			break;
		}
	}
	if(bFlag==true)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
