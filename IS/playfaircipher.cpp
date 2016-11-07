#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void encrypt(char a[5][5],char *tmp,char *enc)
{
	int i,l,m,n,o,lg=strlen(tmp);
	for(i=0;i<lg;i=i+2)
	{
			for(l=0;l<5;l++)
			{
				for(m=0;m<5;m++)
				{
					if(a[l][m]==tmp[i])
						break;
				}
				if(m!=5)
					break;
			}
			for(n=0;n<5;n++)
			{
				for(o=0;o<5;o++)
				{
					if(a[n][o]==tmp[i+1])
					{
						break;
					}
				}
				if(o!=5)
					break;
			}
			if(l<n)
			{
				if(m<o)
				{
					enc[i]=a[l][o];
					enc[i+1]=a[n][m];
				}
				else if(m==o)
				{
					 enc[i]=a[l+1][m];
					 if(n==4)
					 {
					 	enc[i+1]=a[0][m];
					 }
					 else
					 {
					 	enc[i+1]=a[n+1][m];
					 }
				}
				else if(m>o)
				{
					enc[i]=a[l][o];
					enc[i+1]=a[n][m];	
				}
			}
			else if(l==n)
			{
				if(m<o)
				{
					enc[i]=a[l][m+1];
					if(o==4)
					{
						enc[i+1]=a[l][0];
					}
					else
					{
						enc[i+1]=a[l][o+1];
					}
				}
				else if(m>o)
				{
					enc[i+1]=a[l][o+1];
					if(m==4)
					{
						enc[i]=a[l][0];
					}
					else
					{
						enc[i]=a[l][m+1];
					}
				}
			}
			else if(l>n)
			{
				if(m<o)
				{
					enc[i]=a[l][o];
					enc[i+1]=a[n][m];	
				}
				else if(m==o)
				{
					enc[i+1]=a[n+1][m];
					if(l==4)
					{
						enc[i]=a[0][m];
					}
					else
					{
						enc[i]=a[l+1][m];
					}
				}
				else if(m>o)
				{
					enc[i]=a[l][o];
					enc[i+1]=a[n][m];	
				}
			}
	}
	enc[i]='\0';
}
void decrypt(char a[5][5],char *tmp,char *dec)
{
	int i,l,m,n,o,lg=strlen(tmp);
	for(i=0;i<lg;i=i+2)
	{
			for(l=0;l<5;l++)
			{
				for(m=0;m<5;m++)
				{
					if(a[l][m]==tmp[i])
						break;
				}
				if(m!=5)
					break;
			}
			for(n=0;n<5;n++)
			{
				for(o=0;o<5;o++)
				{
					if(a[n][o]==tmp[i+1])
					{
						break;
					}
				}
				if(o!=5)
					break;
			}
			if(l<n)
			{
				if(m<o)
				{
					dec[i]=a[l][o];
					dec[i+1]=a[n][m];
				}
				else if(m==o)
				{
					 if(l==0)
					 {
					 	dec[i]=a[4][m];
					 }
					 else
					 {
					 	dec[i]=a[l-1][m];
					 }
					 dec[i+1]=a[n-1][o];
				}
				else if(m>o)
				{
					dec[i]=a[l][o];
					dec[i+1]=a[n][m];	
				}
			}
			else if(l==n)
			{
				if(m<o)
				{
					 if(m==0)
					 {
					 	dec[i]=a[l][4];
					 }
					 else
					 {
					 	dec[i]=a[l][m-1];
					 }
					 dec[i+1]=a[n][o-1];
				}
				else if(m>o)
				{
					 dec[i]=a[l][m-1];
					 if(o==0)
					 {
					 	dec[i+1]=a[l][4];
					 }
					 else
					 {
					 	dec[i+1]=a[n][o-1];
					 }
				}
			}
			else if(l>n)
			{
				if(m<o)
				{
					dec[i]=a[l][o];
					dec[i+1]=a[n][m];	
				}
				else if(m==o)
				{
					 dec[i]=a[l-1][m];
					 if(n==0)
					 {
					 	dec[i+1]=a[4][o];
					 }
					 else
					 {
					 	dec[i+1]=a[n-1][o];
					 }
				}
				else if(m>o)
				{
					dec[i]=a[l][o];
					dec[i+1]=a[n][m];	
				}
			}
	}	
	dec[i]='\0';
}
int searcha(char a[5][5],char b)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(a[i][j]==b)
			{
				return -1;
			}
		}
	}
	return 1;
}
int search(char *b,char a,int k)
{
	for(int i=0;i<=k;i++)
	{
		if(b[i]==a)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	char  a[5][5];
	char enc[50];
	char dec[50];
	char b[50];
	cout<<"PLAYFAIR CIPHER "<<endl<<endl;
	int lg;
	int f1,f2;
	int i,j;
	f1=0;
	f2=0;
	while(f1==0&&f2==0)
	{
		cout<<"Enter the keyword :";
		cin>>b;
		lg=strlen(b);
		for(i=0;i<lg;i++)
		{
			if(b[i]=='i')
				f1=1;
			if(b[i]=='j')
				f2=1;
		}
		if(f1==1&&f2==1)
		{
			cout<<"Keyword must not contain both i and j "<<endl;
			f1=0;
			f2=0;
		}
		else
		{
			f1=1;
			f2=1;
		}
	}
	int k=0;
	int l,m;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			a[i][j]='\0';
		}
	}
	for(i=0;i<lg;i++)
	{
		if(b[i]=='j')
			b[i]='i';
	}
	a[0][0]=b[0];
	l=0;m=1;
	for(i=1;i<lg;i++)
	{
		 k=search(b,b[i],i-1);
		 if(k==-1)
		 {
		 	a[l][m]=b[i];
		 	m++;
		 	if(m==5)
		 	{
		 		m=0;
		 		l++;
		 		if(l==5)
		 		{
		 			break;
		 		}
		 	}
		 }
	}
	char d[25];
	char bc='a';
	for(i=0;i<25;i++)
	{
		d[i]=bc;
		bc++;
		if(bc=='j')
			bc++;
	}
	for(i=0;i<25;i++)
	{
			bc=d[i];
			k=searcha(a,bc);//searching element d[i] in  matrix a
			if(k==1)
			{
				a[l][m]=d[i];
				m++;
				if(m==5)
				{
					m=0;
					l++;
					if(l==5)
					{
						break;
					}
				}
			}
	}
	cout<<endl<<" The playcipher matrix is :"<<endl<<endl;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			cout<<a[i][j]<<"   ";
		}
		cout<<endl;
	}
	char msg[50],tmp[50];
	cout<<endl<<"Enter the message to be encrypted "<<endl;
	cin>>msg;
	lg=strlen(msg);
	for(i=0;i<lg;i++)
	{
		if(msg[i]=='j')
			msg[i]='i';
	}
	k=0;
	for(i=0;i<lg;i++)
	{
		if((i+1)<lg&&msg[i]==msg[i+1])
		{
			tmp[k]=msg[i];
			tmp[k+1]='x';
			k=k+2;
		}
		else{
			tmp[k]=msg[i];
			k++;
		}
	}
	tmp[k]='\0';
	lg=strlen(tmp);
	if(lg%2!=0)
	{
		tmp[lg]='x';
		tmp[lg+1]='\0';
		lg++;
	}
	int n,o;
	cout<<"The message after padding is :";
	lg=strlen(tmp);
	for(i=0;i<lg;i+=2)
	{
		cout<<tmp[i]<<tmp[i+1]<<" ";
	}
	cout<<endl;
	encrypt(a,tmp,enc);	
	lg=strlen(enc);
	for(i=0;i<lg;i++)
	{
		enc[i]=toupper(enc[i]);
	}
	cout<<"The encrypted message is     :"<<enc<<endl;
	for(i=0;i<lg;i++)
	{
		enc[i]=tolower(enc[i]);
	}
	decrypt(a,enc,dec);
	cout<<"The decrypted message is     :";
	lg=strlen(dec);
	for(i=0;i<lg;i++)
	{
		if(dec[i]!='x')
			cout<<dec[i];
	}
	cout<<endl;
	getch();
	return 0;
}
