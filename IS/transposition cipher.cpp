#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void encrypt(char *msg,char *enc)
{
	int i,l=strlen(msg);
	int j=0;
	for(i=0;i<l;i+=2)
	{
		enc[j++]=msg[i];
	}
	for(i=1;i<l;i+=2)
	{
		enc[j++]=msg[i];
	}
	enc[j]='\0';
}
void decrypt(char *enc,char *dec)
{
	int i,l=strlen(enc);
	int j=0;
	for(i=0;i<l;i++)
	{
		dec[j]=enc[i];
		j=j+2;
		if(j>=l)
			break;
	}
	j=1;
	i++;
	for(;i<l;i++)
	{
		dec[j]=enc[i];
		j=j+2;
	}
	dec[l]='\0';
}
int main()
{
	char msg[100],enc[100],dec[100];
	cout<<"    TRANSPOSITION CIPHER "<<endl<<endl;
	cout<<"Enter the message to be encrypted :";
	gets(msg);
	encrypt(msg,enc);
	cout<<"The encrypted message is :"<<enc<<endl;
	decrypt(enc,dec);
	cout<<"The decrypted message is :"<<dec<<endl;
	getch();
	return 0;
}
