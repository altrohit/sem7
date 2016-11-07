#include<iostream>
#include<conio.h>
#include<string.h>
#include<ctime>
#include<stdlib.h>
using namespace std;
int index(char *random,char a)
{
	for(int i=0;i<26;i++)
	{
		if(random[i]==a)
			return i;
	}
	return -1;
}
void encrypt(char *mes,char *random,char *enc)
{
	int i,in,l=strlen(mes);
	for(i=0;i<l;i++)
	{
		in=((int)toupper(mes[i])-65);
		if(in>=0 &&in<=25)
			enc[i]=random[in];
		else
			enc[i]=mes[i];
	}
	cout<<endl;
	enc[i]='\0';
}
void decrypt(char *enc,char *random,char *dec)
{
	int i,j,l=strlen(enc);
	for(i=0;i<l;i++)
	{
		j=index(random,enc[i]);
		if(j==-1)
			dec[i]=enc[i];
		else
			dec[i]=char(j+97);
	}
	dec[i]='\0';
}
int search(char *random,char a)
{
	for(int i=0;i<26;i++)
	{
		if(random[i]==a)
			return 0;
	}
	return 1;
}
int main()
{
	char mes[100],enc[100],dec[100],random[26];
	cout<<"Enter the message to be encrypted :";
	gets(mes);
	char map[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
	srand((unsigned)time(0)); 
    int size=0;
    while(size!=25)
    {
    	int j=rand()%26;
    	int s=search(random,map[j]);
    	if(s==1)
    	{
    		random[size++]=map[j];
    	}
    }
    cout<<"The random key corresponding to alphabets is"<<endl;
    for(int i=0;i<26;i++)
    	cout<<map[i]<<"  ";
    cout<<endl;
    for(int i=0;i<26;i++)
    	cout<<random[i]<<"  ";
    cout<<endl;
    encrypt(mes,random,enc);
    cout<<"The encrypted message is :"<<enc<<endl;
    decrypt(mes,random,dec);
    cout<<"The decrypted message is :"<<dec<<endl;
	getch();
	return 0;
}
