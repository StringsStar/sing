#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::vector<string> vec;
int O[20]={0};

int main()
{
	int nSets,nLoop=0;
	string str;
	while(cin>>nSets && nSets!=0)
	{
		nLoop++;
		vec.clear();
		for(int i=0;i<nSets;i++)
		{ 
			cin>>str; vec.push_back(str); 
			if(i%2 == 0)
				O[i/2]=i;
			else
				O[nSets-i/2-1]=i;
		}

		cout<<"SET "<<nLoop<<endl;
		for(int i=0;i<nSets;i++)
			cout<<vec[O[i]]<<endl;
	}
}
