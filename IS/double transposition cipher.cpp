#include<iostream>
#include<conio.h>
#include<string.h>
#include<cmath>
#define size 100
#define col 5
using namespace std;
void transpose(char *mes,char *enc,int *porder)
{
	int l=strlen(mes);
	int row=ceil(l/5);
	char matrix[row][5];
	int i,j,k;
	j=k=0;
	for(i=0;i<l;i++)
	{
		matrix[j][k]=mes[i];
		k++;
		if(k==5)
		{
			k=0;
			j++;
		}
	}
	 for(i=0;i<row;i++)
	 {
	 	for(j=0;j<5;j++)
	 	{
	 		cout<<matrix[i][j]<<"  ";
	 	}
	 	cout<<endl;
	 }
	i=0;
	int m=0;
	//read coulumn by column
	for(j=0;j<5;j++)
	{
		m=porder[j];
		for(k=0;k<row;k++)
		{
			
			enc[i++]=matrix[k][m];
			if(i==l)
				break;
		}
		if(i==l)
			break;
	}
	enc[i]='\0';
}
void encrypt(char *mes,char *enc,int *porder,int no)
{
	for(int i=1;i<=no;i++)
	{
		cout<<"Iteration  "<<i<<endl;
		cout<<"Matrix"<<endl;
		transpose(mes,enc,porder);
		cout<<"Encrypted message :"<<enc<<endl;
	}
}
void retranspose(char *enc,char *dec,int *porder)
{
	int l=strlen(enc);
	int row=ceil(l/5);
	int matrix[row][5];
	int i,j,k;
	j=k=0;
	int m;
	for(i=0;i<5;i++)
	{
		for(j=0;j<row;j++)
		{
			m=porder[i];
			matrix[j][m]=enc[k++];
		}
	}
	k=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<5;j++)
		{
			 
			dec[k]=matrix[i][j];
			k++;
		}
	}
	dec[k]='\0';
}
void decrypt(char *enc,char *dec,int *porder,int no)
{
	for(int i=1;i<=no;i++)
		retranspose(enc,dec,porder);
	int l=strlen(dec);
	while(dec[--l]=='x');
	dec[++l]='\0';
}
int main()
{
	char mes[size],enc[size],dec[size];
	int porder[5],i;
	cout<<"Enter the message :";
	cin>>mes;
	cout<<"Enter the permutation order of 5 columns \n";
	for(i=0;i<5;i++)
	{
		cout<<(i+1)<<" :";
		cin>>porder[i];
	}
	cout<<"Enter the number of permutations to be applied :";
	int no;
	cin>>no;
	int l=strlen(mes);
	while(l%col!=0)
	{
		mes[l]='x';
		mes[l+1]='\0';
		l=strlen(mes);
	}
	encrypt(mes,enc,porder,no);
	cout<<"The encrypted message is :"<<enc<<endl;
	decrypt(enc,dec,porder,no);
	cout<<"The decrypted message is :"<<dec<<endl;
	getch();
	return 0;
}
