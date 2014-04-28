#include <iostream>
#include <algorithm> 
#include <vector>
#include <string>
using namespace std;

float Pos[3][3] = {{4.5,150,200},\
	{6.0,300,500},\
	{5.0,200,300} };

std::vector<string> V;
int main()
{
	V.push_back("Wide Receiver");
	V.push_back("Lineman");
	V.push_back("Quarterback");
	
	float x,y,z;
	while(cin>>x>>y>>z &&\
			(x!=0 || y!=0 || z!=0) )
	{
		bool bFlag=false;
		for(int i=0;i<3;i++)
		{
			if(x<=Pos[i][0] && y>=Pos[i][1] && z>=Pos[i][2]) {
				bFlag = true;
				cout<<V[i]<<" ";
			}
		}
		if(bFlag == false) 
			cout<<"No positions";

		cout<<endl;
	}
	return 0;
}
