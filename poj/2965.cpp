#include <iostream>
#include <queue>
//#include <unistd.h>
//This Program is a bit of awkward
//always timeout
//but sometimes can ac
using namespace std;

unsigned short parent[65535]={0};
bool flag[65535]={0};
unsigned short step[65535];

unsigned short GetOrigState()
{
	unsigned short uTemp=0;
	char c;
	int nLoop=16;
	while(nLoop--)
	{
		cin>>c;
		if(c=='+')
			uTemp |= 1<<nLoop;	
	}
	return uTemp;
}

unsigned short Click(unsigned short uFirst,int n)
{
	//rightbottom to topleft 0~15
	unsigned short uTemp=0;
	int nRow=n/4;
	int nCol=n%4;
	for(int i=0 ; i < 4 ; i++)	{
		uTemp |= 1<<( (3-nRow)*4+i);
	}
	for(int i=0 ; i<4 ; i++) {
		uTemp |= 1<<(i*4 + 3-nCol);
	}	

	return uFirst^uTemp;
}

bool bfs(unsigned short uNum)
{
	std::queue<unsigned short>	Q;
	Q.push(uNum);
	while(!Q.empty() )
	{
		unsigned short uFront = Q.front();
		Q.pop();
		for(int i=0 ; i < 16 ; i++)
		{
			unsigned short uCur = Click(uFront,i);	
			if(uCur == 0) {
				flag[uCur] = true;
				parent[uCur] = uFront;
				step[uCur] = i;
				return true;
			}

			if(flag[uCur]==false)
			{
				flag[uCur]=true;
				parent[uCur] = uFront;
				step[uCur] = i;
				Q.push(uCur);
			}
		}
	}
	return false;
}

void ShowAllSteps()
{
	unsigned short uTemp=0;
	int nLoop=0;
	int nBoss[20];
	while(parent[uTemp]!=0)
	{
		nLoop++;
		nBoss[nLoop-1] = step[uTemp];
		uTemp=parent[uTemp];
	}
	cout<<nLoop<<endl;
	//output
	for(int i=nLoop-1 ; i>=0 ; i--)
		cout<<(nBoss[i]/4+1)<<" "<<(nBoss[i]%4+1)<<endl;
}

int main()
{
	unsigned short uOrig = GetOrigState();
	flag[uOrig] = true;
	parent[uOrig] = 0;

	if(bfs(uOrig) ) 
		ShowAllSteps();
}
