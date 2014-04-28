#include <iostream>
using namespace std;

int P[31][8];
bool Pair(int n2,int n1)
{
  switch(n1)
  {
	case 0:
	  if(n2==1||n2==4||n2==7)
		return true;
	  break;
	case 1:
	  if(n2==0||n2==6)
		return true;
	  break;
	case 4:
	  if(n2==0||n2==3)
		return true;
	  break;
	case 3:
	  if(n2==4)
		return true;
	  break;
	case 6:
	  if(n2==1)
		return true;
	  break;
	case 7:
	  if(n2==0)
		return true;
	  break;
	default:
	  return false;
	
  }
  return false;
}
int main()
{
  P[1][1]=P[1][4]=P[1][7]=1;
  for(int i=2;i<=30;i++)
  {
	for(int j=0;j<8;j++)
	  for(int k=0;k<8;k++)
		if(Pair(j,k) ) {
		  P[i][j] += P[i-1][k]; 
		}
  }

  int nInput;
  while(cin>>nInput && nInput!=-1)
  {
	if(nInput==0)
	  cout<<"1"<<endl;
	else
      cout<<P[nInput][0]<<endl;	
  }
}
