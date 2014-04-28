#include <iostream> 
#include <cstdio> 
#include <cmath>
using namespace std;

bool IsPrime(int N)
{
  int nSqr=sqrt(N);
  for(int i=1;i<=nSqr/2;i++)
  {
    if(N%(2*i+1) == 0)
	  return false;
  }
  return true;
}

int main()
{
  int Num;
  while(cin>>Num&&Num!=0)
  {
	//int nSqr=sqrt(Num);
	int nCount=0;
    for(int i=1;i<=Num/4;i++)	
		if(IsPrime(i*2+1)&&IsPrime(Num-1-2*i)\
			&&(4*i+2)<=Num)
		{ nCount++; }

	cout<<nCount<<endl;
  }
}
