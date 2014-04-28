#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::vector<string> m_Datas;
int m_visit[10000];
int m_order[10000];
int nLength , nSets;

void CalcStringInversions(int nCurSet,string str)
{
	int nA=0,nC=0,nG=0,nT=0;
	int nInversion=0;
	for(int i=nLength-1 ; i >= 0 ; i--)
	{
		char chNow = str.at(i);
		if(chNow=='A')
		{
			nA++;	
		}
		else if(chNow=='C')
		{
			nInversion+=nA;
			nC++;
		}
		else if(chNow=='G')
		{
			nInversion = nInversion + nA + nC;
			nG++;
		}
		else if(chNow=='T')
		{
			nInversion = nInversion + nA + nC + nG;
			nT++;
		}
	}//end of for
	m_visit[nCurSet] = nInversion;
}

void Exchagedata(int nOne , int nTwo)
{
	int nTemp = m_visit[nOne];
	m_visit[nOne] = m_visit[nTwo];
	m_visit[nTwo] = nTemp;

	nTemp = m_order[nOne];
	m_order[nOne] = m_order[nTwo];
	m_order[nTwo] = nTemp;
}

void SortInversion(int nStart,int nEnd)
{
	//QuickSort
	if(nStart >= nEnd )	
		return;

	int nPointer=nStart-1;
	//Get The Item To Middle
	for(int i=nStart ; i <= nEnd ; i++)
	{
		if(m_visit[i] < m_visit[nEnd])	
		{
			nPointer++;
			Exchagedata(nPointer , i);
		}
	}

	nPointer++;
	Exchagedata(nPointer , nEnd);
	
	SortInversion(nStart , nPointer-1);
	SortInversion(nPointer+1 , nEnd);
}

void InitOrder()
{
	for (int i = 0; i < nSets; ++i)
	{
		m_order[i] = i;
	}
}
void PrintAll()
{
	for(int i=0 ; i < nSets ; i++)
	{
		cout<<m_Datas[m_order[i]]<<endl;	
	}
}

int main()
{
	string str;
	cin>>nLength>>nSets;
	int nLoop=nSets;

	getline(cin , str);
	while(nLoop--)
	{
		string str;
		std::getline(cin , str);
		m_Datas.push_back(str);
	}
	//
	InitOrder();
	for(int i=0 ; i < nSets ; i++)
		CalcStringInversions(i , m_Datas[i]);
	
	SortInversion(0 , nSets-1);

	PrintAll();

	return 1;
}
