#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
using namespace std;

char Text[200];

char GetChar(char cTemp)
{
	if(cTemp<'A' || cTemp>'Z')
		return cTemp;

	if(cTemp <= 'E') {
		return (char)('Z'-'E'+cTemp);	
	}
	else {
		return (char)(cTemp - 5);	
	}
}
void OutputStrings()
{
	/*code here*/	
	int nLen = strlen(Text);
	for(int i=0; i < nLen ; i++)
		printf("%c" , GetChar(Text[i]) );
	printf("\n");
}
int main()
{
	string STemp;
	while(std::getline(cin,STemp)&& \
			STemp != "ENDOFINPUT")
	{
		cin.getline(Text , 200);
		OutputStrings();
		std::getline(cin,STemp);
	}
}
