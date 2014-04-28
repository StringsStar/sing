#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool findVowel(string strInput)
{
	for(int i=0;i<strInput.length() ; i++) {
		if(strInput.at(i)=='a' ||\
				strInput.at(i)=='o' ||\
				strInput.at(i)=='e'||\
				strInput.at(i)=='i'||\
				strInput.at(i)=='u')
			return true;
	}
	return false;
}

bool findThree(string strInput)
{
	int nV=0,nN=0,bV=0;
	for(int i=0;i<strInput.length();i++) {
		char c=strInput.at(i);	
		if(c=='a'||c=='o'||c=='e'||c=='i'||c=='u') {
			if(i==0) { bV=1;nV++; }	
			else {
				if(bV==1) { nV++; nN=0; }	
				else { bV=1; nV++;nN=0; }
			}
		} else {
			if(i==0) { bV=0;nN++; }	
			else {
				bV=0; nN++; nV=0; 
			}
		}

		if(nN>=3 || nV>=3)
			return true;
	}
	return false;
}

bool findTwo(string strInput)
{
	char c=strInput.at(0);
	for(int i=1;i<strInput.length();i++) {
		char n= strInput.at(i);
		if(n==c && n!='e' && n!='o')
			return true;
		else {
			c = n;	
		}
	}
	return false;
}

int main()
{
	string str;
	while(cin>>str && str!="end")
	{
		bool bFlag=true;
		while(1) {
			if(findVowel(str) == false) {
				bFlag = false;
				break;
			}
			if(findThree(str) == true) {
				bFlag = false;
				break;
			}
			if(findTwo(str) == true) {
				bFlag = false;
				break;
			}
			///bFlag
			bFlag = true;
			break;
		}
		if(bFlag == true) {
			printf("<%s> is acceptable.\n",str.c_str() );	
		} else {
			printf("<%s> is not acceptable.\n",str.c_str() );	
		}
	}
}
