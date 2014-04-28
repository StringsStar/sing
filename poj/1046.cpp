#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct Color {
	int operator - (const Color& cA)
	{
		int nSum = (cA.nR-nR)*(cA.nR-nR)+(cA.nG-nG)*(cA.nG-nG)+\
							 (cA.nB-nB)*(cA.nB-nB);
		return nSum;
	}
	int nR;
	int nG;
	int nB;
};
Color m_Maps[16];
Color m_Sets[1000];
int nNumbers=0;

int main()
{
	int nR , nG , nB;
	int nLoop=0;
	while(cin>>nR>>nG>>nB && \
			((nR!=-1)||(nG!=-1)||(nB!=-1)) )
	{
		nLoop++;
		if(nLoop<=16) {
			m_Maps[nLoop-1].nR = nR;
			m_Maps[nLoop-1].nG = nG;
			m_Maps[nLoop-1].nB = nB;
		}
		else {
			m_Sets[nLoop-17].nR = nR;
			m_Sets[nLoop-17].nG = nG;
			m_Sets[nLoop-17].nB = nB;
		}
	}
	
	nNumbers = nLoop-16;
	for(int i=0 ; i < nNumbers;i++)
	{
		int nDst = 0;
		int nSum = m_Maps[0]-m_Sets[i];
		for(int j=1;j<16;j++) {
			int nTemp = m_Maps[j]-m_Sets[i];
			if(nTemp < nSum) {
				nSum = nTemp;
				nDst = j;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n" , \
				m_Sets[i].nR,m_Sets[i].nG,m_Sets[i].nB,\
				m_Maps[nDst].nR,m_Maps[nDst].nG,m_Maps[nDst].nB);
	}
	///////////Start To Output
	
	/*code here*/	
}
