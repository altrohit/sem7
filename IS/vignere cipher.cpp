#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int row(char a[27][26],char b)
{
	int i;
	for(i=1;i<27;i++)
	{
		if(a[i][0]==b)
			return i;
	}
}
int col(char a[27][26],char m)
{
	for(int i=0;i<26;i++)
	{
		if(a[0][i]==m)
			return i;
	}
}
void encrypt(char a[27][26],char *msg,char *key,char *enc)
{
	int i,l,r,c;
	char m,b;
	l=strlen(msg);
	for(i=0;i<l;i++)
	{
		m=msg[i];
		b=key[i];
		r=row(a,b);
		c=col(a,m);
		enc[i]=a[r][c];
	}
	enc[i]='\0';
}
int cols(char a[27][26],int r,char m)
{
	for(int i=0;i<26;i++)
	{
		if(a[r][i]==m)
			return i;
	}
}
void decrypt(char a[27][26],char *enc,char *key,char *dec)
{
	int i,l,r,c;
	char m,b;
	l=strlen(enc);
	for(i=0;i<l;i++)
	{
		m=enc[i];
		b=key[i];
		r=row(a,b);
		c=cols(a,r,m);
		dec[i]=a[0][c];
	}
	dec[i]='\0';
}
int main()
{
	char a[27][26];
	char b[26],c='a';
	int i,j,k;
	for(i=0;i<26;i++)
	{
		a[0][i]=c;
		b[i]=c;
		c++;
	}
	for(i=1;i<27;i++)
	{
		k=i-1;
		for(j=0;j<26;j++)
		{
			a[i][j]=b[k++];
			if(k==26)
				k=0;
		}
	}
	char msg[50],key[50],enc[50],dec[50];
	int ml,kl;
	cout<<"Enter the message to be encrypted :";
	cin>>msg;
	cout<<"Enter the keyword :";
	cin>>key;
	ml=strlen(msg);
	kl=strlen(key);
	if(kl>ml)
		kl=ml;
	else if(kl<ml)
	{
		j=0;
		for(i=kl;i<ml;i++)
		{
			key[i]=key[j++];
			if(j==kl)
				j=0;
		}
		key[i]='\0';
	}
	kl=strlen(key); 
	cout<<"Key length is     "<<kl<<endl;
	cout<<"Message length is "<<ml<<endl;
	cout<<"Message :"<<msg<<endl;
	cout<<"Key     :"<<key<<endl;
	cout<<"The Vignere Square is "<<endl<<endl;
	for(i=0;i<27;i++)
	{
		for(j=0;j<26;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
	encrypt(a,msg,key,enc);
	cout<<"The encrypted message is :"<<enc<<endl;
	decrypt(a,enc,key,dec);
	cout<<"The decrypted message is :"<<dec<<endl;
	getch();
	return 0;
}
