#include <iostream> 
#include <cstdio> 
#include <string.h>
using namespace std;

struct Point {
	int nX;
	int nY;
};

int nPoints;
Point PointMap[700];
Point Datas[700][700];
int m_TotalMax=0;

int main()
{
	while(cin>>nPoints && nPoints!=0)
	{
		for(int i=0; i < nPoints; i++) {
			cin>>PointMap[i].nX;
			cin>>PointMap[i].nY;
		}
		//Calc To Datas
		Point m_CurPoints[700];
		int m_Sum[700];
		int m_nCurPointer;
		int m_nExcept;
		m_TotalMax=0;
		for(int i=0;i<nPoints;i++) {
			m_nCurPointer=-1;
			memset(m_Sum , 0 , 700);
			m_nExcept=0;	
			int m_nTemp=2;
			for(int j=i+1;j<nPoints;j++)
			{
				m_nTemp = 2;
				for(int k=j+1 ; k < nPoints ; k++) {
					if( (PointMap[j].nX-PointMap[i].nX)*(PointMap[k].nY-PointMap[i].nY)== \
							(PointMap[j].nY-PointMap[i].nY)*(PointMap[k].nX-PointMap[i].nX) )
						m_nTemp++;
				}
				if(m_nTemp > m_TotalMax)
					m_TotalMax = m_nTemp;
			}
		}

		cout<<m_TotalMax<<endl;	
	}
	//Calc For Biggest Numbers;
	return 0;
}
