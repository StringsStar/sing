#include <iostream> 
#include <cstdio> 
#include <string>
using namespace std;

char S[200][200];

int main() {
	int nCol;
	string str;
	while(cin>>nCol && nCol!=0)
	{
		cin>>str;
		int nRow = str.size()/nCol;
		bool bReverse=false;
		int nChars=0;
		for(int i=0;i<nRow;i++)
		{
			if(bReverse==true) {
				for(int j=nCol-1;j>=0;j--) {
					S[i][j] = str.at(nChars);
					nChars++;
				}
			}	else {
				for(int j=0;j<nCol;j++)	{
					S[i][j] = str.at(nChars);
					nChars++;
				}
			}
			bReverse = (bReverse==true) ? false : true;
		}
		
		//let's output
		for(int j=0;j<nCol;j++)
			for(int i=0;i<nRow;i++)
			{
				printf("%c",S[i][j]);	
			}
		printf("\n");
	}
	return 0;
}
