#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

int nBeds;
string strCustomers;
std::list<char> L;
std::list<char>::iterator it;

int GetWalkAways()
{
	int nWalkAways=0;
	int nLen = strCustomers.size();
	for(int i=0 ; i<nLen ; i++)
	{
		//Judge In Or Out
		char c = strCustomers.at(i);
		it = std::find(L.begin() , L.end() , c);
		//In
		if(it == L.end() ) {
			if(L.size() >= nBeds)	{
				nWalkAways++;
				i++;
			}
			else {
				L.push_back(c);	
			}
		}
		else {
			L.erase(it);	
		}
	}
	return nWalkAways;	
}
int main()
{
	while(cin>>nBeds && nBeds!=0 && cin.ignore(1) && \
			std::getline(cin,strCustomers) )
	{
		int nSum = GetWalkAways();
		if(nSum == 0)
			cout<<"All customers tanned successfully."<<endl;
		else
			cout<<nSum<<" customer(s) walked away."<<endl;
	}
}
