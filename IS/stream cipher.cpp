#include<iostream>
#include<conio.h>
#include<string.h>
#include<cmath>
#define size 100
using namespace std;
void binarytoint(int &n,char *mes)
{
	int l=strlen(mes);
	int j=0;
	n=0;
	for(int i=l-1;i>=0;i--)
	{
		if(mes[i]=='1')
		{
			n=n+pow(2,j);
		}
		j++;
	}
}
void inttobinary(int n,char *mes)
{
	int j=0;
	for(int i=n;i!=0;i=i/2)
	{
		if(i%2==0)
			mes[j++]='0';
		else
			mes[j++]='1';
	}
	mes[j]='\0';
	int l=strlen(mes);
	char temp;
	for(j=0;j<l/2;j++)
	{
		temp=mes[j];
		mes[j]=mes[l-j-1];
		mes[l-j-1]=temp;
	}
}
void encrypt(char *mes,char *key,char *enc)
{
	int i,l=strlen(mes);
	for(i=0;i<l;i++)
	{
		if((mes[i]=='0' && key[i]=='0') ||(mes[i]=='1' && key[i]=='1'))
			enc[i]='0';
		else 
			enc[i]='1';
	}
	enc[i]='\0';
}
void decrypt(char *enc,char *key,char *dec)
{
	int i,l=strlen(enc);
	for(i=0;i<l;i++)
	{
		if((enc[i]=='0' && key[i]=='0') ||(enc[i]=='1' && key[i]=='1'))
			dec[i]='0';
		else 
			dec[i]='1';
	}
	dec[i]='\0';
}
int main()
{
	char mes[size],enc[size],dec[size],key[size],temp[30];
	cout<<"STREAM CIPHER BASED ON XOR OPERATION \n\n";
	int n,k;
	cout<<"Enter the  message to be encrypted :";
	cin>>n;
	inttobinary(n,mes);
	cout<<"Enter the key :";
	cin>>k;
	inttobinary(k,key);
	int l1=strlen(mes);
	int l2=strlen(key);
	while(l1!=l2)
	{
		strcpy(temp,key);
		strcat(key,temp);
		l2=strlen(key);
		if(l2>l1)
		{
			key[l1]='\0';
			l2=l1;
		}
	}
	cout<<"Binary representation"<<endl;
	cout<<"The message is           :"<<mes<<endl;
	cout<<"The key is               :"<<key<<endl;
	encrypt(mes,key,enc);
	cout<<"The binary cipher text   :"<<enc<<endl;
	binarytoint(n,enc);
	cout<<"The encrypted message is : "<<n<<endl;
	decrypt(enc,key,dec);
	binarytoint(n,dec);
	cout<<"The decrypted message is :"<<n<<endl;
	getch();
	return 0;
}
