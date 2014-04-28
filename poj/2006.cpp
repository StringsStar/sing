#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	double x,y,m,n;
	while(cin>>x>>y>>m>>n && \
			(x!=0||y!=0||m!=0||n!=0))
	{
		double H = ((-1*x+(double)sqrt(x*x+4*m*n*x*y) )/(2*n) );
		double pH = -log10(H);
		printf("%0.3lf\n",pH);
	}
	return 0;
}
