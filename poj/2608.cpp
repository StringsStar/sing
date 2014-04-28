#include <iostream> 
using namespace std;

int Code[128]={0};
int main()
{
	Code['B']=Code['F']=Code['P']=Code['V']=1;
	Code['C']=Code['G']=Code['J']=Code['K']=Code['Q']=Code['S']=Code['X']=Code['Z']=2;
	Code['D']=Code['T']=3;
	Code['L']=Code['L']=4;
	Code['M']=Code['N']=5;
	Code['R']=6;
	string str;
	while(cin>>str)
	{
		int nCurCode=0;
		for(int i=0;i<str.length();i++)	
		{
			if(Code[str.at(i)]==0) {
				nCurCode=0;
				continue;
			} else if(Code[str.at(i)]!=nCurCode) {
				cout<<Code[str.at(i)];
				nCurCode = Code[str.at(i)];
			} else
				continue;
		}
		cout<<endl;
	}
}
