#include <iostream> 
#include <algorithm>
#include <string.h>
#include <string>
#include <cstdio>
using namespace std;

string strSets;
int nSets[13];
int nTarget;
int nLength;

int InitNumbers()
{
	int nLoop=0;
	nLength = strSets.size();
	for(int i=0 ; i<nLength ; i++)	
	{
		nSets[i] = strSets.at(i)-'A'+1;
		nLoop++;
	}
	std::sort(nSets , nSets+nLength);
	return 0;
}

bool CrackLock()
{
	for(int v=nLength-1;v>=0;v--)	
		for(int w=nLength-1;w>=0 ;w--) {
			if(w==v)
				continue;
			for(int x=nLength-1;x>=0;x--) {
				if((x==v || x==w) )
						continue;
				for(int y=nLength-1;y>=0 ;y--) {
					if(y==v || y==w || y==x)
						continue;
					for(int z=nLength-1;z>=0 ;z--)
					{
						if(z==v || z==w || z==x || z==y)
							continue;
						if(nSets[v]-nSets[w]*nSets[w]+nSets[x]*nSets[x]*nSets[x]-\
								nSets[y]*nSets[y]*nSets[y]*nSets[y]+\
								nSets[z]*nSets[z]*nSets[z]*nSets[z]*nSets[z]==nTarget)
						{
							printf("%c%c%c%c%c\n",nSets[v]+'A'-1,nSets[w]+'A'-1,nSets[x]+'A'-1,\
									nSets[y]+'A'-1,nSets[z]+'A'-1);	
							return true;
						}
					}
				}
			}
		}
	return false;
}
int main()
{
	while(cin>>nTarget&&cin.ignore(1)&&std::getline(cin,strSets)&&\
			nTarget !=0 && strSets != "END" )
	{
		InitNumbers();
		if(!CrackLock() )
			cout<<"no solution"<<endl;
	}
	/*code here*/	
}
