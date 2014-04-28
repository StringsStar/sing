#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

std::vector<string> Pat;
std::vector<string> Find;
int main()
{
	string strT;
	while(std::getline(cin,strT) && \
			strT != "XXXXXX")
	{
		Pat.push_back(strT);	
	}
	std::sort(Pat.begin() , Pat.end() );
	while(std::getline(cin,strT) && \
			strT != "XXXXXX")
	{
		Find.push_back(strT);	
	}
	int nSize = Find.size();
	int nPat = Pat.size();
	for(int i=0 ; i<nSize ; i++)
	{
		bool bFound=false;

		for(int j=0;j<nPat;j++)	{
			int nStrLen = Find[i].length();
			bool bNot=false;
			int nVist[100]={0};
			if(nStrLen == Pat[j].length() )	{
				for(int k=0;k<nStrLen;k++)	{
					int Nret=-1;
					while(1) {
					int Npos = Nret+1;
					Nret = Pat[j].find(Find[i].at(k),Npos);
					//cout<<"Npos"<<Npos<<"K "<<k<<"Find "<<Find[i].at(k)<<endl;
					if(string::npos==Nret) {
						bNot = true;
						break;
					}
					if(nVist[Nret]==0) {
						nVist[Nret] = 1;
						break;
					}
					else 
						continue;
				}
					if(bNot==true)
						break;
			}
				if(bNot == false) {
					bFound = true;
					cout<<Pat[j]<<endl;
				}
			}
		}//end of loop pat

		if(bFound==false)
			cout<<"NOT A VALID WORD"<<endl;
		cout<<"******"<<endl;
	}
}
