#include <iostream> 
#include <cstdio> 
#include <string>
using namespace std;

int main()
{
	string str;
	char Chars[26];
	for(int i=0;i<26;i++)
		cin>>Chars[i];

	//Read A line
	std::getline(cin,str);
	std::getline(cin,str);
	for(int i=0;i<str.length();i++)
	{
		char c = str.at(i);
		if(c>='a' && c<='z')
			printf("%c",Chars[c-'a']);
		else if(c==' ')
			printf(" ");
		else if(c>='A' && c<='Z')
		{
			char Temp = Chars[c-'A']-32;	
			printf("%c",Temp);
		}
	}
	printf("\n");
	return 0;
}
