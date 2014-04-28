#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int nSeqs;
  int nLoop=0;
  cin>>nSeqs;
  long long a,b;
  while(nSeqs--)
  {
	nLoop++;
	printf("Scenario #%d:\n",nLoop);
	cin>>a>>b;
	long long sum=(a+b)*(b-a+1);
	cout<<sum/2<<endl<<endl;
  }
  return 0;
}
