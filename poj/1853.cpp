#include <iostream> 
#include <cstdio> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

float fLeft,fRight;
int nSets; //point to nSets-1
float F[100];
std::vector<int> Q;

bool FindAver(int nStart)
{
	float fSum=0;
	for(int i=0;i<Q.size();i++) {
		fSum += F[Q[i]];
	}
	for(int i=nStart+1;i<=nSets;i++)
	{
		if((fSum+F[i])>fLeft && (fSum+F[i])<fRight) {
			Q.push_back(i);
			return true;
		} else if((fSum+F[i]) > fRight) {
			continue;
		} else {
			Q.push_back(i);
			if(FindAver(i) )
				return true;
			Q.pop_back();
		}
	}
	return false;
}

int main()
{
	while(cin>>nSets && nSets!=0)
	{
		float fSum=0;
		int nLoop=0;
		//clear queue
		Q.clear();
		int nSigma=nSets;
		while(nSigma--) {
			nLoop++;
			cin>>F[nLoop];
			fSum += F[nLoop];
		}
		fLeft=fSum/2.02;
		fRight = fSum/1.98;
		if( FindAver(0) ==true) {
		cout<<Q[0];
		for(int i=1; i<Q.size();i++)
			cout<<" "<<Q[i];
		} 
		cout<<endl;
	}
}
