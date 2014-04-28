#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char trasfer(char ch)
{
	if(ch=='W')ch='Q';
	else if(ch=='S')ch='A';
	else if(ch=='X')ch='Z';
	else if(ch=='E')ch='W';
	else if(ch=='D')ch='S';
	else if(ch=='C')ch='X';
	else if(ch=='R')ch='E';
	else if(ch=='F')ch='D';
	else if(ch=='V')ch='C';
	else if(ch=='T')ch='R';
	else if(ch=='G')ch='F';
	else if(ch=='B')ch='V';
	else if(ch=='Y')ch='T';
	else if(ch=='H')ch='G';
	else if(ch=='N')ch='B';
	else if(ch=='U')ch='Y';
	else if(ch=='J')ch='H';
	else if(ch=='M')ch='N';
	else if(ch=='I')ch='U';
	else if(ch=='K')ch='J';
	else if(ch==',')ch='M';
	else if(ch=='O')ch='I';
	else if(ch=='L')ch='K';
	else if(ch=='.')ch=',';
	else if(ch=='P')ch='O';
	else if(ch=='[')ch='P';
	else if(ch==']')ch='[';
	else if(ch=='\\')ch=']';
	else if(ch==';')ch='L';
	else if(ch=='/')ch='.';
	else if(ch=='2')ch='1';
	else if(ch=='3')ch='2';
	else if(ch=='4')ch='3';
	else if(ch=='5')ch='4';
	else if(ch=='6')ch='5';
	else if(ch=='7')ch='6';
	else if(ch=='8')ch='7';
	else if(ch=='9')ch='8';
	else if(ch=='0')ch='9';
	else if(ch=='-')ch='0';
	else if(ch=='=')ch='-';
	else if(ch=='\'')ch=';';
	return ch;
}

int main()
{
	char str[10000];
	while(gets(str))
	{
		for (int i=0;i<strlen(str);++i)
		str[i]=trasfer(str[i]);
		puts(str);
	}
	return 0;
}
