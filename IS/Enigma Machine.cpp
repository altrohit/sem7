#include<iostream>
#include<conio.h>
#include<string.h>
#define size 100
using namespace std;
int c1,c2,c3;
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
void lower(char *a)
{
	int l=strlen(a);
	for(int i=0;i<l;i++)
	{
		a[i]=tolower(a[i]);
	}
}
int find(char *a,char b)
{
	for(int i=0;i<27;i++)
	{
		if(a[i]==b)
		return i;
	}
	return -1;
}
void encrypt(char *msg,char *enc,char *map,char *rotor1,char *rotor2,char *rotor3,char *reflector)
{
	c1=c2=c3=0;
	int i,j,k,l,n,m=0;
	l=strlen(msg);
	for(i=0;i<l;i++)
	{
		j=find(map,msg[i]);
		k=find(map,rotor3[j]);
		j=find(map,rotor2[k]);
		k=find(map,rotor1[j]);
		j=find(map,reflector[k]);
		k=find(rotor1,map[j]);
		j=find(rotor2,map[k]);
		k=find(rotor3,map[j]);
		enc[m++]=map[k];
		rotate(rotor3);
		c3++;
		if(c3%26==0)
		{
			rotate(rotor2);
			c2++;
			if(c2%26==0)
			{
				rotate(rotor1);
				c1++;
			}
		}
	}
	enc[m]='\0';
}
void decrypt(char *enc,char *dec,char *map,char *rotor1,char *rotor2,char *rotor3,char *reflector)
{
	c1=c2=c3=0;
	int i,j,k,l,m=0;
	l=strlen(enc);
	for(i=0;i<l;i++)
	{
				j=find(map,enc[i]);
				k=find(map,rotor3[j]);
				j=find(map,rotor2[k]);
				k=find(map,rotor1[j]);
				j=find(map,reflector[k]);
				k=find(rotor1,map[j]);
				j=find(rotor2,map[k]);
				k=find(rotor3,map[j]);
				dec[m++]=map[k];
				rotate(rotor3);
		c3++;
		if(c3%26==0)
		{
			rotate(rotor2);
			c2++;
			if(c2%26==0)
			{
				rotate(rotor1);
				c1++;
			}
		}
	}
	dec[m]='\0';
	
}
int main()
{
	char msg[size],enc[size],dec[size];
	char       map[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
	char    rotor1[27]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','\0'};
	char    rotor2[27]={'m','n','b','v','c','x','z','a','s','d','f','g','h','j','k','l','p','o','i','u','y','t','r','e','w','q','\0'};
	char    rotor3[27]={'l','k','j','h','g','f','d','s','a','q','w','e','r','t','y','u','i','o','p','m','n','b','v','c','x','z','\0'};
    char reflector[27]={'y','r','u','h','q','s','l','d','p','x','n','g','o','k','m','i','e','b','f','z','c','w','v','j','a','t','\0'};
	cout<<"Enter the message to be encrypted :";
	cin>>msg;
	lower(msg);
	char a,b,c;
	cout<<"Enter the initial settings of the rotor 3:";
	cin>>a;
	cout<<"Enter the initial settings of the rotor 2:";
	cin>>b;
	cout<<"Enter the initial settings of the rotor 1:";
	cin>>c;
	while(rotor3[0]!=a)
		rotate(rotor3);
	while(rotor2[0]!=b)
		rotate(rotor2);
	while(rotor1[0]!=c)
		rotate(rotor1);
	encrypt(msg,enc,map,rotor1,rotor2,rotor3,reflector);
	cout<<"The encrypted message is :"<<enc<<endl;
	while(rotor3[0]!=a)
		rotate(rotor3);
	while(rotor2[0]!=b)
		rotate(rotor2);
	while(rotor1[0]!=c)
		rotate(rotor1);
	decrypt(enc,dec,map,rotor1,rotor2,rotor3,reflector);
	cout<<"The decrypted message is :"<<dec<<endl;
	getch();
	return 0;
}
