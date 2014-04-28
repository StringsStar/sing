#include <iostream> 
#include <cstdio> 

using namespace std;

int main() {
	int nInput;
	cin>>nInput;

	for(int i=3 ; i <= nInput ; i++) {
		for(int j=2 ; j<nInput ; j++)	{
			for(int k=2 ; k<nInput; k++) {
				if(k<j)
					continue;
				for(int r=2 ; r<nInput ; r++)
				{
					if(r<k)
						continue;
					if(i*i*i==j*j*j+k*k*k+r*r*r) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,r);							
					}
				}
			}
		}
	}
}
