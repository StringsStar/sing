#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  float f;
  float T;
  cin>>f;
  while(cin>>T && T!=999)
  {
	printf("%.2f\n",T-f);
	f=T;
  }
  printf("End of Output\n");
}
