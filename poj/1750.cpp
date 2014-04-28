#include <iostream>
#include <cstdio>
#include <string> 
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

//Queue has no iterator begin end 
std::vector<string> VecStrs;
std::list<string> Q;
std::list<string>::iterator it;

int N[1000]={0};
int nCurNum=0;
void Output(string str,int n)
{
	for(int i=0;i<N[n];i++)	
		cout<<" ";
	cout<<str<<endl;
}
int main() {
	string str;
	int nLoop=0;
	while(cin>>str) {
		nLoop++;
		if(nLoop==1) {
			N[nLoop] = 0;
			nCurNum++;
			Q.push_front(str.substr(0,1) );
			Output(str , nLoop);
			continue;
		}
		int nCount=0;
		int nTemp=nCurNum;
		for(it = Q.begin();it!=Q.end() ;it++) {			
			if(str.substr(0,nTemp) !=*it)	{
				nCount++;
				continue;
			} else {
				break;	
			}
			nTemp--;
		}
		Q.erase(Q.begin(),it--);
		N[nLoop] = nTemp-1;
		if(Q.empty() ) {
			Q.push_front(str.substr(0,1) );
			Output(str , nLoop);
			continue;
		}
		if(str.size() > Q.front().size() ) {
			nCurNum++;
			Q.push_front(str.substr(0,nCurNum) );
			Output(str,nLoop);
			continue;
		} else {
			Output(str,nLoop);	
		}
	}
	return 0;
}
