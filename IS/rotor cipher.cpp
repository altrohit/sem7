#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void rotate(char *temp)
{
	int i,l=strlen(temp);
	char t=temp[l-1];
	for(i=l-1;i>0;i--)
	{
		temp[i]=temp[i-1];
	}
	temp[0]=t;
}
void encrypt(char *msg,char *key,char *enc)
{
	char temp[26];
	strcpy(temp,key);
	int i,l,index;
	l=strlen(msg);
	for(i=0;i<l;i++)
	{
		if(msg[i]==' ' || msg[i]>='0' && msg[i]<='9')
			enc[i]=msg[i];
		else
		{
			msg[i]=toupper(msg[i]);
			index=(int)msg[i]-65;
			enc[i]=temp[index];
			rotate(temp);
		}
	}
	enc[i]='\0';
}
int index(char *temp,char a)
{
	int i, l=strlen(temp);
	for(i=0;i<l;i++)
	{
		if(temp[i]==a)
			return i;
	}
	return -1;
}
void decrypt(char *enc,char *key,char *dec)
{
	char temp[26];
	strcpy(temp,key);
	int i,t,l=strlen(enc);
	for(i=0;i<l;i++)
	{
		if(enc[i]==' ' || enc[i]>='0' && enc[i]<='9')
			dec[i]=enc[i];
		else
		{
			t=index(temp,enc[i]);
			dec[i]=(char)(t+65);
			dec[i]=tolower(dec[i]);
			rotate(temp);
		}
	}
	dec[i]='\0';
}
int main()
{
	char msg[100],key[26],enc[100],dec[100];
	int l=0;
	cout<<"       ROTOR CIPHER"<<endl<<endl;
	cout<<"Enter the message :";
	gets(msg);
	while(l!=26)
	{	
		cout<<"Enter the initial setting of the rotor machine:";
		cin>>key;
		l=strlen(key);
		if(l!=26)
			cout<<"Key must be 26 characters long"<<endl;
	}
	encrypt(msg,key,enc);
	cout<<"The encrypted message is :"<<enc<<endl;
	decrypt(enc,key,dec);
	cout<<"The decrypted message is :"<<dec<<endl;
	getch();
	return 0;
}
