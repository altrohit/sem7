#include<iostream>
#include<cmath>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int inverse(int a,int b)
{
	for(int i=1;i<=10000;i++)
		if((a*i)%b==1)
			return i;
	return -1;
}
int crt(int a,int b,int p,int q)
{
	int M=p*q;
	int M1=M/p;
	int M2=M/q;
	int M1i,M2i;
	M1i=inverse(M1,p);
	M2i=inverse(M2,q);
	if(M1i==-1 || M2i==-1)
		cout<<"Error"<<endl;
	int ans=(a*M1*M1i+ b*M2*M2i)%(p*q);
	return ans;
}
void encrypt(int mes,int pkey,int &enc)
{
	enc=(mes*mes)%pkey;
}
void decrypt(int enc,int p,int q,int *dec)
{
	int a1,a2,b1,b2;
	int cp=enc%p;
	int dp=enc%q;
	a1=(int)pow(cp,(p+1)/4)%p;
	a2=p-a1;
	b1=(int)pow(dp,(q+1)/4)%q;
	b2=q-b1;
	dec[0]=crt(a1,b1,p,q);
	dec[1]=crt(a1,b2,p,q);
	dec[2]=crt(a2,b1,p,q);
	dec[3]=crt(a2,b2,p,q);
}
int checkprime(int n)
{
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	for(int i=2;i<=n/2;i=i+2)
	{
		if(n%2==0)
			return 0;
	}
	return 1;
}
int main()
{
	int lprime=1,cprime=1,pkey,mes,enc,dec[4];
	cout<<"          RABIN CIPHER"<<endl;
	cout<<"Enter two prime numbers which are in the form 4k+3 and not equal"<<endl;
	cout<<"Enter first prime number :";
	cin>>lprime;
	cout<<"Enter second prime number :";
	cin>>cprime;
	pkey=lprime*cprime;
	do{
		system("cls");
	cout<<"Enter the message to be encrypted in the range "<<2<<" to "<<lprime*cprime<<" :";
	cin>>mes;
	encrypt(mes,pkey,enc);
	cout<<"The encrypted message is :"<<enc<<endl;
	decrypt(enc,lprime,cprime,dec);
	cout<<"The decrypted messages are :"<<dec[0]<<"  "<<dec[1]<<"  "<<dec[2]<<"  "<<dec[3]<<endl;
	getch();}
	while(true);
	return 0;
}
