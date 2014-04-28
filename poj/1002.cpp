#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int FetchCharDigit(char chSrc)
{
	if(chSrc=='A' || chSrc=='B' || chSrc=='C')
		return 2;
	else if(chSrc=='D' || chSrc=='E' || chSrc=='F')
		return 3;
	else if(chSrc=='G' || chSrc=='H' || chSrc=='I')
		return 4;
	else if(chSrc=='J' || chSrc=='K' || chSrc=='L')
		return 5;
	else if(chSrc=='M' || chSrc=='N' || chSrc=='O')
		return 6;
	else if(chSrc=='P' || chSrc=='R' || chSrc=='S')
		return 7;
	else if(chSrc=='T' || chSrc=='U' || chSrc=='V')
		return 8;
	else if(chSrc=='W' || chSrc=='X' || chSrc=='Y')
		return 9;
	else if(chSrc>='0' && chSrc<='9')
		return (chSrc-'0');
	else return -1;
}

int visit[10000000]={0};
bool bVist[10000000]={0};
std::priority_queue<int> q;
std::vector<int> vec;
int FromStringToInt(string str)
{
	int nLoop=0;
	int nSum=0;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if(str.at(i) == '-')
			continue;
		
		int nDigit=FetchCharDigit(str.at(i));
		if (nDigit < 0)
		{
			continue;
		}
		nSum = nSum*10 + nDigit;
		nLoop ++;
	}
	if(nLoop != 7)
		return -1;
	
	return nSum;
}

void ShowAllData()
{
	std::sort(vec.begin() , vec.end() );
	std::reverse(vec.begin() , vec.end() );
	if(vec.empty() )
	{
		cout<<"No duplicates."<<endl;
		return;
	}

	int nDup=0;
	while(!vec.empty() )
	{
		int nTop=vec.back();
		vec.pop_back();

		if(visit[nTop] <= 1)
			continue;

		nDup++;
	//	printf("%03d-%04d %d\n",nTop/10000,nTop%10000,visit[nTop]);
		cout<<setfill('0')<<setw(3)<<nTop/10000<<"-"<<setfill('0')<<setw(4)<<\
		nTop%10000<<" "<<visit[nTop]<<endl;
	}
	if(nDup == 0)
		cout<<"No duplicates."<<endl;
	//cout<<nTop<<" "<<visit[nTop]<<endl;
}

int main()
{
	string str;
	while(getline(cin , str))
	{
		int nNum = FromStringToInt(str);
		if(nNum < 0 )
			continue;
		
		visit[nNum]++;
		if(visit[nNum] >= 2 && !bVist[nNum])
			vec.push_back(nNum), bVist[nNum]=true;
	}
	ShowAllData();
	return 1;	
}
