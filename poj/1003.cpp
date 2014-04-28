#include <iostream>
using namespace std;

int GetOvers(float pSum)
{
	float pCur = 0;
	int nLoop=0;
	while(pCur < pSum)
	{
		nLoop++;
		float pN = 1.0 / (nLoop+1);
		pCur += pN;
	}
	return nLoop;
}
int main(int argc, char const *argv[])
{
	float pSum;
	while(1)	
	{
		cin >> pSum;
		if(pSum == 0)
			break;

		int nLen = GetOvers(pSum);
		cout << nLen <<" card(s)"<<endl;
	}

	return 0;
}

