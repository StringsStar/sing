//g++
#include <iostream> 
#include <cstdio> 
using namespace std;

int GetInt(string str)
{
	if(str == "too high")
		return 2;
	else if(str == "too low")
		return 1;
	else if(str == "right on")
		return 0;
}

void printGood()
{
	printf("Stan may be honest\n");	
}

void printBad()
{
	printf("Stan is dishonest\n");	
}

int main()
{
	int nFirst;
	while(cin>>nFirst && nFirst!=0)
	{
		string str;
		bool bFlag = true;
		int N[11] = {0};
		//let's 1 for small 2 for large
		std::getline(cin,str);
	  std::getline(cin,str);
    N[nFirst] = GetInt(str);
		if(N[nFirst] == 0) {
			printGood();
			continue;
		}

		int nTemp;
		while(cin>>nTemp && std::getline(cin,str) &&\
				std::getline(cin,str) && GetInt(str)!=0 )
		{
			if(N[nTemp]!=0 && N[nTemp]!=GetInt(str) )
				bFlag = false;
			N[nTemp] = GetInt(str);	
		}
		//last is the right on
		for(int i=1; i< 11;i++)
		{
			if(i>=nTemp && N[i]==1) {
				bFlag = false;
				break;
			}	else if(i<=nTemp && N[i]==2) {
				bFlag = false;
				break;
			}
		}
		if(bFlag == true)
			printGood();
		else 
			printBad();
	}
}
