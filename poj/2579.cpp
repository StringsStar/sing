#include <iostream> 
#include <cstdio> 
using namespace std;

int OMap[9][9];
int FMap[8][8];
int main()
{
	int nRow,nCol;	
	string str;
	while(cin>>str && str!="ENDOFINPUT")
	{
		cin>>nRow>>nCol;
		for(int i=0;i<nRow;i++)
			for(int j=0;j<nCol;j++)
			{
				char c;
				cin>>c;
				OMap[i][j] = c-'0';
			}
		cin>>str; //ignore END

		//let's output
		for(int i=0;i<nRow-1;i++) {
			for(int j=0;j<nCol-1;j++)
			{
				FMap[i][j] = (OMap[i][j]+OMap[i][j+1]+\
						OMap[i+1][j]+OMap[i+1][j+1])/4;
				printf("%d",FMap[i][j]);
			}
			printf("\n");
		}
	}
}
