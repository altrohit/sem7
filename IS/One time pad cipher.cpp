#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void encrypt(char *msg,char *key,char *enc)
{
	int l=strlen(msg);
	int i;
	for(i=0;i<l;i++)
	{
		if(msg[i]==' ' || msg[i]>='0'&&msg[i]<='9')
			enc[i]=msg[i];
		else
		{
			msg[i]=toupper(msg[i]);
			key[i]=toupper(key[i]);
			enc[i]=(char)(((int)msg[i]-65+(int)key[i]-65)%26)+65;
			
		}
	}
	enc[i]='\0';
}
void decrypt(char *enc,char *key,char *dec)
{
	
	int l=strlen(enc);
	int i,temp;
	for(i=0;i<l;i++)
	{
		if(enc[i]==' ' || enc[i]>='0'&&enc[i]<='9')
			dec[i]=enc[i];
		else
		{
			temp=(int)enc[i]-(int)key[i];
			if(temp<0)
				temp=temp%26+26;
			else
				temp=temp%26;
			dec[i]=temp+97;
		}
	}
	dec[i]='\0';
}
int main()
{
	char msg[100],key[100],enc[100],dec[100], temp[30];
	int l1,l2=0;
	cout<<"     ONE TIME PAD CIPHER "<<endl<<endl;
	cout<<"Enter the message :";
	gets(msg);
	l1=strlen(msg);
	cout<<"Enter the key :";
	gets(key);
	while(l1!=l2)
	{
		l2=strlen(key);
		if(l1!=l2)
			{
				strcpy(temp,key);
				strcat(key,temp);
				l2=strlen(key);
				if(l2>l1)
				{
					key[l1]='\0';
				}
			}
	}
	cout<<"The key is "<<key<<endl;
	encrypt(msg,key,enc);
	cout<<"The encrypted message is :"<<enc<<endl;
	decrypt(enc,key,dec);
	cout<<"The decrypted message is :"<<dec<<endl;
	getch();
	return 0;
}
