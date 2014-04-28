#include <iostream>
using namespace std;

int Board[4][4];
int visit[65535]={0};
int m_nDepth=-1;

int Check()
{
	int nLine1 = Board[0][0]<<3 | Board[0][1]<<2 | Board[0][2]<<1 | Board[0][3];
	int nLine2 = Board[1][0]<<3 | Board[1][1]<<2 | Board[1][2]<<1 | Board[1][3];
	int nLine3 = Board[2][0]<<3 | Board[2][1]<<2 | Board[2][2]<<1 | Board[2][3];
	int nLine4 = Board[3][0]<<3 | Board[3][1]<<2 | Board[3][2]<<1 | Board[3][3];
	return nLine1<<12 | nLine2<<8 | nLine3<<4 | nLine4;
}

void Flip(int nDot)
{
	int nRow = nDot/4;
	int nCol = nDot % 4;
	
	Board[nRow][nCol] = Board[nRow][nCol]==1 ? 0 : 1;
	if( (nRow-1)>=0 )
		Board[nRow-1][nCol] = Board[nRow-1][nCol]==1 ? 0 : 1;
	if( (nRow+1)<=3 )
		Board[nRow+1][nCol] = Board[nRow+1][nCol]==1 ? 0 : 1;
	if( (nCol-1)>=0 )
		Board[nRow][nCol-1] = Board[nRow][nCol-1]==1 ? 0 : 1;
	if( (nCol+1)<=3 )
		Board[nRow][nCol+1] = Board[nRow][nCol+1]==1 ? 0 : 1;
}

void UnFlip(int nDot)
{
	Flip(nDot);
}
bool FlipBoard(int nDepth)
{
	int nVisit=0;
	int nLocVisit[16]={0};
	for(int i=0 ; i < 16 ; i++)		
	{
		Flip(i);
		int nSum = Check();
		if(nSum==0 || nSum==65535)
		{
				m_nDepth = nDepth;
				return true;
		}
		if(visit[nSum] == false)
		{
			nVisit ++;
			visit[nSum] = true;
			nLocVisit[i] = 1;
		}
		UnFlip(i);
	}

	if(nVisit == 0)
		return false;
	//Start Deal nLocVisit
	for(int i=0 ; i < 16 ; i++)
	{
		if(nLocVisit[i] != 0)
		{
			Flip(i);
			if(FlipBoard(nDepth++) )
				return true;
			UnFlip(i);
		}
	}

	return false;
}
int main()
{
	for(int i=0 ; i < 4 ; i++)	
	{
		string strInfo;
		std::getline(cin , strInfo);
		for(int j=0 ; j < 4 ; j++)
		{
			Board[i][j] = (strInfo.at(j)=='b') ? 0 : 1;
		}
	}

	if(FlipBoard(0) )
	{
		cout<<m_nDepth;
	}
	else
		cout<<"Impossible"<<endl;
	return 0;
}
