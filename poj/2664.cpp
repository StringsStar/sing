#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

std::vector<string> V;
int main()
{
	int nChose,nCat;
	string S;
	while(cin>>nChose && nChose!=0)
	{
		cin>>nCat;	
		V.clear();
		for(int i=0;i<nChose;i++) {
			cin>>S;
			V.push_back(S);
		}
		//
		bool bFlag=true;
		for(int i=0;i<nCat;i++) {
			int nMax,nMin;
			int nCur=0;
			cin>>nMax>>nMin;
			for(int j=0;j<nMax;j++) {
				cin>>S;
				if(std::find(V.begin(),V.end(),S)!=V.end() )
					nCur++;
			}
			if(nCur<nMin)
				bFlag=false;
		}
		//let's output
		if(bFlag==true)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}
